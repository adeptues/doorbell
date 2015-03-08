package com.thelmkay.hannotifier;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

import org.fusesource.mqtt.client.BlockingConnection;
import org.fusesource.mqtt.client.MQTT;
import org.fusesource.mqtt.client.Message;
import org.fusesource.mqtt.client.QoS;
import org.fusesource.mqtt.client.Topic;

import java.net.URISyntaxException;
import java.security.MessageDigest;

public class MQTTService extends Service {
    private static final  String TAG = "MQTTService";
    private NotificationManager mNM;
    private boolean run = false;
//1883
    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        throw new UnsupportedOperationException("Not yet implemented");
    }

    public void onCreate(){
        mNM = (NotificationManager)getSystemService(NOTIFICATION_SERVICE);

    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId){
        Log.i(TAG, "Received start id " + startId + ": " + intent);

        return START_STICKY;
    }

    private void doMQTT(){
        String host = "10.0.2.2";
        int port  = 1883;
        MQTT mqtt = new MQTT();
        BlockingConnection blockingConnection = null;
        try {
            mqtt.setHost(host,port);
            Topic[] topics = {new Topic("foo", QoS.AT_LEAST_ONCE)};
            blockingConnection = mqtt.blockingConnection();
            blockingConnection.connect();
            blockingConnection.subscribe(topics);

                Message message = blockingConnection.receive();
                Log.d(TAG,"Message topic: "+message.getTopic());
                byte []  bytes = message.getPayload();

            String d = new String(bytes);
            Log.d(TAG,"Payload is "+d);




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

    @Override
    public void onDestroy() {
        // Cancel the persistent notification.
      /*  mNM.cancel(NOTIFICATION);

        // Tell the user we stopped.
        Toast.makeText(this, R.string.local_service_stopped, Toast.LENGTH_SHORT).show();*/
    }
}
