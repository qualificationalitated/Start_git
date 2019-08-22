package com.example.recycleviewexample;

import androidx.annotation.NonNull;

import java.io.File;

import okhttp3.MediaType;
import okhttp3.MultipartBody;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

/**
 * Created by baehyeonbin on 2017. 11. 4..
 */

public class RetrofitUtil {
    public static Retrofit retrofit = new Retrofit.Builder()
            .baseUrl("http://purplebeen.kr:3000")
            .addConverterFactory(GsonConverterFactory.create())
            .build();

    public static final String MULTIPART_FORM_DATA = "multipart/form-data";

//    public static Retrofit getLoginRetrofit() {
//        OkHttpClient.Builder httpClient = new OkHttpClient.Builder();
//        httpClient.addInterceptor(chain -> {
//            Request original = chain.request();
//            Request request = original.newBuilder()
//                    .method(original.method(), original.body())
//                    .build();
//            return chain.proceed(request);
//        });
//
//        OkHttpClient client = httpClient.build();
//        Retrofit retrofit = new Retrofit.Builder()
//                .baseUrl("http://n0rr.iptime.org:3333")
//                .addConverterFactory(GsonConverterFactory.create())
//                .client(client)
//                .build();
//        return retrofit;
//    }

    public static MultipartBody.Part createMultipartBody(@NonNull File file, String name) {
        RequestBody mFile = RequestBody.create(MediaType.parse("images/*"), file);
        MultipartBody.Part fileToUpload = MultipartBody.Part.createFormData(name, file.getName(), mFile);
        return fileToUpload;
    }
    public static RequestBody createRequestBody(@NonNull String value) {
        return RequestBody.create(MediaType.parse(MULTIPART_FORM_DATA), value);
    }
}