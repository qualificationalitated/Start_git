package com.example.recycleviewexample;

import com.example.recycleviewexample.model.AuthRequest;
import com.example.recycleviewexample.model.AuthResponse;
import com.example.recycleviewexample.model.DefaultResponse;
import com.example.recycleviewexample.model.User;

import okhttp3.MultipartBody;
import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.Multipart;
import retrofit2.http.POST;
import retrofit2.http.Part;

public interface Userservice {
    @Multipart
    @POST("/users")
    Call<DefaultResponse> apply(@Part("data") User user, @Part MultipartBody.Part profile);

    @POST("/sign")
    Call<AuthResponse> sign(@Body AuthRequest authRequest);
}
