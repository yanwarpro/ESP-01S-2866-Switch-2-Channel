Disini saya memodifikasi ESP 01s 8266 1 Channel dengan menambahkan 1 relay lagi sehingga totalnya ada 2 relay. Kita pakai applikasi berbasis cloud yaitu Blynk, karena tujuan utamanya supaya bisa diakses lewat internet. Awalnya aku buat versi web, berhubung router di rumahku POP Forwarding-nya ada lebih dari 3 sambungan router, jadinya tidak bisa--harus hubungin teknisi WIFI-Nya. 

Saya memodifikasi beberapa komponen, terutama yang berhubungan dengan pin GPIO2 dengan menambahkan resistor 22K. Tujuannya supaya relay itu bisa aktif dengan memanfaatkan transistor yang ada di relay tersebut yang basis-nya itu aktif di voltage 0,7v. Karena kalau pin GPIO2 di esp 01s 8266 itu aku sambungkan ke IN di relay langsung, maka yang terjadi relay-nya itu nyala terus. Dan saya memakai relay yang kedua dengan relay active low single channel. Kalau kalian pakai relay optocopler, kalian tinggal ubah aja jumper-nya ke active low. 

Projek ini cenderung lebih murah, karena aku beli ESP 8266 01S Single channel itu kebetulan dapat promo dari tokped dapatnya 18rb, aslinya harganya 32rb. Daripada aku harus membeli ESP 8266 2 Channel yang harganya 80rb. 

Kemudian relay tambahan harganya tidak nyampai 7500 rupiah. Jadi total 27.500 rupiah. 

Tujuan membuat ini untuk apa?
Yaitu untuk bisa menghidupkan PC saya di rumah yang kebetulan ada UPS-nya. Jadi saya butuh 2 relay, yang satu untuk menyalakan UPS dulu, kemudian relay yang satunya untuk menyalakan PC-nya. Sebenarnya bisa saja langsung ketika UPS nyala kemudian PC nyala dengan menggunakan modul momentary on dengan relay 5 pin seperti yang ada di sini: https://www.tokopedia.com/trikid/modul-momentary-on-dengan-relay-5-pin-modul-set?extParam=whid%3D12879643%26src%3Dchat tapi harganya menurutku mahal, 75rb itupun charger-nya harus beli lagi. Saya cari akal gimana supaya ESP 01S 8266 tadi bisa ditambahkan relay. Dan hasil percobaanku ternyata works. 

Cara upload-nya ke ESP 01S 8266 tadi gimana?
Cukup upload pakai adapter USB to TTL ESP8266 base board, dengan menyambung antara pin GPIO0 dengan GND ketika upload codingnya dengan mamakai Arduino IDE. Bentuknya seperti ini: https://shopee.co.id/USB-to-ESP8266-Base-Board-Programmer-Board-i.13486297.6353639731

ESP 01S 8266 seperti ini: https://www.tokopedia.com/snapshot_product?dtl_id=4129052520&order_id=1933116183

Projek Real-nya:
![IMG_20241006_061541](https://github.com/user-attachments/assets/bf64ba3b-1d7b-4f21-b58b-31763c8bc0bd)


UPDATE 1
Penambahan loop untuk menyambungkan wifi selama 10 detik jika wifi terputus dan membuat kondisi saklar tetap ON meski wifi terputus, sampai terkoneksi dan adanya perubahan data dari Blynk. Ini bertujuan supaya PC tidak kemudian mati ketika wifi terputus.

Program ini cocok untuk menghidupkan UPS dan PC 

Skema
![Scheme](https://github.com/user-attachments/assets/bb950931-0cdd-41d8-8886-4822ea83a509)

UPDATE 2
Berhubung di ESP 8266 tadi ada 2 pin yang nganggur (GPIO1 dan GPI03), maka akan aku manfaatkan dengan menambah 2 saklar lagi yaitu untuk menghidupkan lampu kamar dan kipas angin. 

