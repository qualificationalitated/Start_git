package com.example.githubloginfirebasetest

import android.os.Bundle
import android.text.TextUtils
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.githubloginfirebasetest.databinding.ActivityLoginBinding
import com.google.android.gms.tasks.OnFailureListener
import com.google.android.gms.tasks.OnSuccessListener
import com.google.firebase.auth.AuthResult
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.OAuthProvider
import com.google.firebase.auth.ktx.auth
import com.google.firebase.ktx.Firebase
import com.google.firebase.auth.FirebaseUser


class LoginActivity : AppCompatActivity() {
    private lateinit var binding: ActivityLoginBinding
    private lateinit var auth: FirebaseAuth
    // 빌더로 OAuthProvider의 인스턴스를 생성
    private val provider = OAuthProvider.newBuilder("github.com")

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityLoginBinding.inflate(layoutInflater)
        setContentView(binding.root)

        auth = Firebase.auth

        initGitHubLoginButton()
    }

    private fun initGitHubLoginButton() {
        binding.loginGithubButton.setOnClickListener {
            if (TextUtils.isEmpty(binding.emailEditText.text.toString())) {
                Toast.makeText(this, "깃허브 아이디를 입력해주세요.", Toast.LENGTH_LONG).show()
            } else {
                // 선택사항: OAuth 요청과 함께 전송하고자 하는 커스텀 OAuth 매개변수를 추가로 지정합니다.
                provider.addCustomParameter("login", getInputEmail())

                auth.startActivityForSignInWithProvider( /* activity= */this, provider.build())
                    .addOnSuccessListener(
                        OnSuccessListener<AuthResult?> { authResult ->
                            auth.signInWithCredential(authResult.credential!!)
                                .addOnCompleteListener(this@LoginActivity) { task ->
                                    if (task.isSuccessful) {
                                        // 로그인 성공 시 호출될 콜백 함수
                                        val user = auth.currentUser
                                        if (user != null) {
                                            // 로그인 성공한 사용자 정보 출력
                                            val displayName = user.displayName
                                            val email = user.email
                                            val uid = user.uid
                                            Toast.makeText(this@LoginActivity, "displayName: $displayName, email: $email, uid: $uid", Toast.LENGTH_LONG).show()
                                        }
                                        finish()
                                    } else {
                                        Toast.makeText(this, "깃허브 로그인 실패", Toast.LENGTH_LONG).show()
                                    }
                                }
                        })
                    .addOnFailureListener(
                        OnFailureListener {
                            Toast.makeText(this, "Error : $it", Toast.LENGTH_LONG).show()
                        })
            }
        }
    }

    private fun getInputEmail(): String {
        return binding.emailEditText.text.toString().trim()
    }
}
