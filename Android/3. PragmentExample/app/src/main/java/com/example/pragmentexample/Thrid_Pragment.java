package com.example.pragmentexample;

import android.content.Context;
import android.net.Uri;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;


public class Thrid_Pragment extends Fragment {
    public Thrid_Pragment() {
        // Required empty public constructor
    }


    public static Thrid_Pragment newInstance() {
        Thrid_Pragment fragment = new Thrid_Pragment();
        return fragment;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_thrid__pragment, container, false);
    }
}
