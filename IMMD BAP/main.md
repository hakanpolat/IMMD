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
* Toplam çıkış gücü, Faz sayısı, Kutup sayısı, Oluk sayısı, Boyutlar
* Kienle Spiess incelenecek.
* Kollmorgen'a mail atılacak.
* Bir tasarım aracı geliştirilecek (MATLAB). Bloklar arası ilişkiler zamanla dahil edilecek.
* Cogging torque araştırılacak. Fractional slot, 10/12 12/14 gibi standart kutup sayısı oranları incelenecek.
* PM BLDC ile ilgili kitap ve makale okunup tasarıma girdi olacak bilgiler edinilecek.

## İş paketi-2
* Sürücü modül sayısı, bağlantı şekli (seri-paralel), topoloji seçimi

## İş paketi-3
* GaN üretici seçimi, gerilim ratingi seçimi
* **Commercial GaN EVMleri için fiyat istenecek.**

## İş paketi-4
* MCU benchmart ve seçimi, master-slave olayı, haberleşme protokolü

## İş paketi-5
* RL load tasarımı

## Donanım geliştirme yöntemi
* PCB tasarlanacak, üretilecek.
* Motor seçilecek veya tasarlanacak, üretilecek.
* PCB parça parça RL load ile test edilecek.
* PCB tümüyle RL load ile test edilecek.
* Motor standart bir sürücü ile test edilecek.
* PCB motora takılmadan motoru parça parça sürecek.
* PCB motora takılmadan motoru tümüyle sürecek.
* PCB motora takılacak ve tümüyle test edilecek.

## Sorular
* Akım ölçümüne gerek var mı?
* Heat sink mekanik pozisyonu ve bağlantısı nasıl olacak? Frame yapılacak mı?

## Sistem parçaları
* Kaynak
  * 3-faz, 400V, 50 Hz şebeke
* Rectifier tarafı
  * 3-faz Diode bridge rectifier
  * Kesici
  * Soft start devresi
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
  * Input: DC bara (500-600V aralık), Output: 15V veya 24V
  * Diğer güç dönüştürücüleri: 5V, 3.3V, ISO5V vb.
* Mekanik
  * Heat sink
  * Shaft
  * Frame
  * etc.
