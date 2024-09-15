Disini saya memodifikasi ESP 01s 2866 1 Channel dengan menambahkan 1 relay lagi sehingga totalnya ada 2 relay. Kita pakai applikasi berbasis cloud yaitu Blynk, karena tujuan utamanya supaya bisa diakses lewat internet. Awalnya aku buat versi web, berhubung router di rumahku POP Forwarding-nya ada lebih dari 3 sambungan router, jadinya tidak bisa--harus hubungin teknisi WIFI-Nya. 

Saya memodifikasi beberapa komponen, terutama yang berhubungan dengan pin GPIO2 dengan menambahkan resistor 22K. Tujuannya supaya relay itu bisa aktif dengan memanfaatkan transistor yang ada di relay tersebut yang basis-nya itu aktif di voltage 0,7v. Karena kalau pin GPIO2 di esp 01s 2866 itu aku sambungkan ke IN di relay langsung, maka yang terjadi relay-nya itu nyala terus. Dan saya memakai relay yang kedua dengan relay active low single channel. Kalau kalian pakai relay optocopler, kalian tinggal ubah aja jumper-nya ke active low. 

Projek ini cenderung lebih murah, karena aku beli ESP 2866 Single channel itu kebetulan dapat promo dari tokped dapatnya 18rb, aslinya harganya 32rb. Daripada aku harus membeli ESP 2866 2 Channel yang harganya 80rb. 

Kemudian relay tambahan harganya tidak nyampai 7500 rupiah. Jadi total 27.500 rupiah. 

Tujuan membuat ini untuk apa?
Yaitu untuk bisa menghidupkan PC saya di rumah yang kebetulan ada UPS-nya. Jadi saya butuh 2, relay yang satu untuk menyalakan UPS dulu, kemudian relay yang satunnya untuk menyalakan PC-nya. Sebenarnya bisa saja langsung ketika UPS nyala kemudian PC nyala dengan menggunakan modul momentary on dengan relay 5 pin seperti yang ada di sini: https://www.tokopedia.com/trikid/modul-momentary-on-dengan-relay-5-pin-modul-set?extParam=whid%3D12879643%26src%3Dchat tapi harganya menurutku mahal. 75rb itupun chargenya harus beli lagi. Saya cari akal gimana supaya ESP 01S 2866 tadi bisa ditambahkan relay. Dan hasil percobaanku ternyata works. 
