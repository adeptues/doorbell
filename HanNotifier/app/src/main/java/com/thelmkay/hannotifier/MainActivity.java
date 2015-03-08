package com.thelmkay.hannotifier;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.support.v4.app.NotificationCompat;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;

import org.fusesource.mqtt.client.BlockingConnection;
import org.fusesource.mqtt.client.MQTT;
import org.fusesource.mqtt.client.Message;
import org.fusesource.mqtt.client.QoS;
import org.fusesource.mqtt.client.Topic;

import java.net.URISyntaxException;


public class MainActivity extends ActionBarActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void sendNotification(View view){
        EditText editText = (EditText)findViewById(R.id.editText);
        String text = editText.getText().toString();
        Log.d("HanNotifier","text is "+text);

        //Blank intent to allow autocancelation
        Intent intent = new Intent();
        int mdId = 1;
        NotificationCompat.Builder mBuilder =
                new NotificationCompat.Builder(this)//needs a fucking icon
                        .setSmallIcon(R.drawable.btn_check_buttonless_on)
                        .setContentTitle("My notification")
                        .setContentText("Hello World!").setAutoCancel(true)
                        .setContentIntent((PendingIntent.getActivity(getApplicationContext(), mdId, intent, PendingIntent.FLAG_CANCEL_CURRENT)));



        NotificationManager mNotificationManager =
                (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
// mId allows you to update the notification later on.
        mNotificationManager.notify(mdId, mBuilder.build());


        Log.d("HanNotifier","text is "+text);
    }

    public void  recievedMessage(View view){
        doMQTT();
    }

    private void doMQTT(){
        String host = "10.0.2.2";
        int port  = 1883;
        Log.d(TAG,"Creating mqtt");
        MQTT mqtt = new MQTT();
        Log.d(TAG,"MQTT created");
        BlockingConnection blockingConnection = null;
        try {
            mqtt.setHost(host,port);
            Topic[] topics = {new Topic("foo", QoS.AT_LEAST_ONCE)};
            Log.d(TAG,"Host and port set");
            Log.d(TAG,"Attempting to create blocking connection ...");
            blockingConnection = mqtt.blockingConnection();
            blockingConnection.connect();
            Log.d(TAG,"Blocking connection created!.");
            Log.d(TAG,"Attempting to subscribe ...");
            blockingConnection.subscribe(topics);
            Log.d(TAG,"Subscribed!");
            Message message = blockingConnection.receive();
            Log.d(TAG,"Message topic: "+message.getTopic());
            byte []  bytes = message.getPayload();

            String d = new String(bytes);
            Log.d(TAG,"Payload is "+d);
            message.ack();



        } catch (URISyntaxException e) {
            Log.e(TAG,"Host is invalid",e);
        } catch (Exception e) {
            Log.e(TAG,"Failed to subscirbe to topics",e);
        }finally {
            if (blockingConnection != null) {
                try {
                    blockingConnection.disconnect();
                } catch (Exception e) {
                    Log.e(TAG,"Error when closing connection",e);
                }
            }
        }



    }
}
