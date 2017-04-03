In this document, plans for BAP project will be discussed.
* İş-zaman planı: OK
* Maliyet planı: OK
* Yürütme belgesi: OK
* Satın alma planı: OK
* GaN ve MCU için sample mailleri: OK
* Preliminary design: OK
* Proje başlatma: OK
* Motor seçimi: OK

## İş paketi-1: Motor seçimi (PM BLDC)
* Toplam çıkış gücü
* Faz sayısı
* Kutup sayısı
* Oluk sayısı
* Boyutlar

## İş paketi-2
* Sürücü modül sayısı, bağlantı şekli (seri-paralel), topoloji seçimi

## İş paketi-3
* GaN üretici seçimi, gerilim ratingi seçimi

## İş paketi-4
* MCU benchmart ve seçimi, master-slave olayı, haberleşme protokolü

## İş paketi-5
* RL load tasarımı

## Sorular
* Integration yapılacak mı? Devre ayrı bir yerde mi çalıştırılacak?
* Devre öne mi arkaya mı gelecek?
* Akım ölçümüne gerek var mı?
* Heat sink mekanik pozisyonu ve bağlantısı nasıl olacak?

## Sistem parçaları
* Kaynak
  * 3-faz, 400V, 50 Hz şebeke
* Rectifier tarafı
  * 3-faz Diode bridge rectifier
  * Kesici
* DC Bara
  * 540V DC bara gerilimi
  * %1 ripple hedefi
  * Inductor
  * Capacitor
* Motor sürücü
  * 4x3-faz bridge inverter (ayrı ayrı tek faz yapılabilir)
  * 2seri-2paralel bağlantı (GaN'dan dolayı seri sayısı meçhul)
  * 600V GaN (değişebilir)
* Motor
  * 8kW çıkış gücü
  * 8-kutuplu
  * 4x3-faz sargılar
  * PM rotor
* Sensörler
  * DC bara gerilimi (birden fazla olabilir)
  * 1xPozisyon sensörü
  * 4x3-faz akım ölçümü (gerekli mi?)
* Mikrodenetleyici (MCU)
  * 4x3pwm modül gerekli (pair halinde)
  * 4xDSP (slave olarak çalışacak)
  * 1xDSP (master olarak çalışacak)
* Kontrol devreleri
  * 4x3 Gate drive devresi
  * Sensör ölçüm devreleri
* Power supply
  * Flyback converter
  * Input: DC bara, output: 15V veya 24V
  * Diğer güç dönüştürücüleri: 5V, 3.3V vb.
* Heat sink
  * ?????
