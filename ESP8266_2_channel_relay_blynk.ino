/**********************************************************************************
 *  TITLE: Blynk control 2 Relays using ESP-01 (ESP-01/01s) with active-Low relays
 *  by Tech StudyCell, modified for 2 relays with active-Low logic
 **********************************************************************************/

/* Fill-in your Template ID, Name, and Auth Token */
#define BLYNK_TEMPLATE_ID "TMPL69Pr88HmB"
#define BLYNK_TEMPLATE_NAME "UPS Rumah"
#define BLYNK_AUTH_TOKEN "EilKTJ3TK4FGQ1EK5abvLqQBeVyh5kc3"  // Auth token dari Blynk

// Your WiFi credentials.
char ssid[] = "ARIS";  // Nama WiFi
char pass[] = "bismillah2023";  // Password WiFi

#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h>

// Define the GPIO connected with relays
#define RelayPin1 0  // GPIO0 untuk relay pertama
#define RelayPin2 2  // GPIO3 untuk relay kedua

// Define virtual pins for the buttons in the Blynk app
#define VPIN_BUTTON_1 V1  // Virtual Pin untuk relay pertama
#define VPIN_BUTTON_2 V2  // Virtual Pin untuk relay kedua

// Relay State
bool toggleState_1 = LOW;  // initial state for relay 1 (OFF)
bool toggleState_2 = LOW;  // initial state for relay 2 (OFF)

// When App button is pushed - switch the state
BLYNK_WRITE(VPIN_BUTTON_1) {
  toggleState_1 = param.asInt();  // Dapatkan nilai dari aplikasi Blynk
  digitalWrite(RelayPin1, !toggleState_1);  // Kontrol relay pertama (active-Low)
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  toggleState_2 = param.asInt();  // Dapatkan nilai dari aplikasi Blynk
  digitalWrite(RelayPin2, !toggleState_2);  // Kontrol relay kedua (active-Low)
}

void reconnectWiFi() {
  // Coba hubungkan ulang ke WiFi jika tidak terhubung
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi terputus. Mencoba menghubungkan kembali...");
    WiFi.begin(ssid, pass);
    
    // Coba hubungkan selama 10 detik
    unsigned long startAttemptTime = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
      delay(500);
      Serial.print(".");
    }
    
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("WiFi terhubung kembali.");
      Serial.println(WiFi.localIP());  // Cetak alamat IP
    } else {
      Serial.println("Gagal terhubung ke WiFi.");
    }
  }
}

void setup() {
  Serial.begin(9600);  // Mulai komunikasi serial untuk debugging
  
  pinMode(RelayPin1, OUTPUT);  // Set pin relay pertama sebagai output
  pinMode(RelayPin2, OUTPUT);  // Set pin relay kedua sebagai output
  
  // Inisialisasi relay dengan status OFF (Low-active)
  digitalWrite(RelayPin1, HIGH);  // Relay pertama OFF (Low-active)
  digitalWrite(RelayPin2, LOW);  // Relay kedua OFF (Low-active)
  
  // Hubungkan ke WiFi
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  // Cetak alamat IP
  
  // Hubungkan ke Blynk Cloud
  Blynk.config(BLYNK_AUTH_TOKEN);  // Mengatur Blynk dengan auth token
  Blynk.connect();  // Terhubung ke Blynk
  
  // Sinkronisasi status relay dengan Blynk Cloud
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
}

void loop() {
  // Jalankan Blynk
  Blynk.run();
  
  // Cek dan hubungkan ulang WiFi jika terputus
  reconnectWiFi();
  
  // Cek status koneksi Blynk dan WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected, relay states will remain as is.");
    delay(1000);
  }
}
