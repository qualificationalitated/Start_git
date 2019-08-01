package com.example.pragmentexample;

import android.content.Context;
import android.net.Uri;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;



public class first_pragnent extends Fragment {
    public first_pragnent() {
        // Required empty public constructor
    }


    // TODO: Rename and change types and number of parameters
    public static first_pragnent newInstance() {
        first_pragnent fragment = new first_pragnent();
        return fragment;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_first_pragnent, container, false);
    }
}