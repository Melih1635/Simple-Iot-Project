# Simple-Iot-Project
Project is a example of measuring the tempature and sending that data to thingspeak following that if there is a emergency in the data then tweet the tempature  to the twitter
Gerekli kütüphaneleri eklendi. ThingSpeak IP yi belirttim. Analog pini A0 olarak atadım. Gerilim, sicaklik, sensor değişkenleri oluşurdum. Gerçekteki oda sıcaklığını sicaklik değişkeni gösterecek. Bu tanımlamalardan sonra bağlanacağımız wifi bilgilerini girdim.
ThingSpeak kanal numaramı, field numaramı, thingspeakin bize verdiği writeapikeyi yazdım.
Setup ta band hızını, wifi kontrolünü, thingspeak kodunu yazdım.
Loop  kısmında wifi bağlantısı kontrol edilir.
Onun altındaki kısımda analog pindeki sıcaklık değeri okunur. Gerilim içi sensor 1023 e bölünür. 0 dan 1023 e 1024 değer olduğundan bize en üst değer lazım. NodeMCU 3,3 volt ile çalıştığından 3300 ile çarptım.
LM35ten net değer bulmak içi en son gerilimi 10 a böldüm. Seri port ekranına sonucu yazdırıp en alt satırda thingspeak e bunu ekledim.
Sıcaklık koşula göre gönderilir.
Sıcaklık gönderme fonksiyonu içninde  gerekli izin, bağlantı türünü, ip ve portu girdik. Ardından thingspeak üzerinden tweet atmak için bilgileri yazdık. Statustan sonraki yazıklarımız yollnmak istenen tweet oluyor.


Cihazlar: LM35 sıcaklık sensör,Esp8266 Wifi,
 Veriler:ThingSpeak,Twitter
 Bağlantı:Wifi
 Teknoloji kullanıcıları:Kullanıcı
