package com.thelmkay.hannotifier;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

/**
 * Created by thelmkay on 08/03/15.
 */
public class BootCompletedReceiver extends BroadcastReceiver {
    private static final String TAG = "BootCompletedReciever";
    @Override
    public void onReceive(Context context, Intent intent) {
        Log.w(TAG,"Starting service MQTT service ...");

    }
}
