### Haziran 2019

##### Tasarım - donanım çalışmaları
1. **Motor sürücü**
  * **Kontrol kartı testi:** Flyback noise problemi. PWM bufferların kalan 3 tanesi düzeltilmeli.
  * **Kontrol DSP yazılımı:** EQEP çalıştırılacak ve mevcut kontrolcüye entegre edilecek. Simulink üzerinde kontrol simulasyonu tamamlanacak.
  * **Versiyon 1.3 gate driver kartı:** İki kartın akım ölçümleri test edildi. 3 kart daha dizilecek.
  * **Heat sink:** Diğerlerinin kesimine karar verilecek.
  * **Seri-Paralel çalışma:** Paralel ve seri nominal gerilime kadar test edilecek. Interleaving için DSP kodu yazılacak.
2. **Motor**
  * **Generatör mod:** Yük testi ???
  * **Motor modu:** Test edilecek ???

##### Teorik çalışmalar
1. **Modülerlik:** ECCE makalesindeki simulasyonlar yeni kartta tekrarlanacak. Analitik modelleme yapılacak. Testler yapılacak (seri-paralel).
2. **Dengesizlik:** Gerilim dengesizliği üzerine modelleme yapılıyor.
3. **Termal model:** Modeldeki aksaklıklar üzerine çalışılacak.

##### Makale çalışmaları
1. **IET JoPE:** Special issue submit edildi.
2. **IET JoE:** Yayınlanmaya hazır.
3. **ECCE 2019:** Kabul edildi. Full-paper yazılacak.
4. [**Ufuktaki Konferanslar**](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)

##### Tez çalışmaları
1. **Outline:** Tamamlanacak.

##### Proje, rapor, satın almalar
1. **Bütçe:** Avans aktarmaları yapılacak ve kapatılacak.

________


### Mayıs 2019

##### Tasarım - donanım çalışmaları
1. **Motor sürücü**
  * **Kontrol kartı testi:** Flyback noise problemi. PWM bufferların kalan 3 tanesi düzeltilmeli.
  * **Kontrol DSP yazılımı:** EQEP çalıştırılacak ve mevcut kontrolcüye entegre edilecek. Simulink üzerinde kontrol simulasyonu tamamlanacak.
  * **Versiyon 1.3 gate driver kartı:** 2 kart sorunsuz çalışıyor. Akım ölçümleri test edilmedi. 3 kart daha dizilmeli.
  * **Heat sink:** Diğerlerinin kesimine karar verilecek.
  * **Seri-Paralel çalışma:** Paralel 200V'a, seri 100V'a kadar test edildi. Interleaving için DSP kodu yazılacak.
2. **Motor**
  * **Generatör mod:** Yük testi ???
  * **Motor modu:** Test edilecek ???

##### Teorik çalışmalar
1. **Modülerlik:** ECCE makalesindeki simulasyonlar yeni kartta tekrarlanacak. Analitik modelleme çalışılacak.
2. **Dengesizlik:** Gerilim dengesizliği üzerine modelleme yapılıyor.
3. **Termal model:** Modeldeki aksaklıklar üzerine çalışılacak.

##### Makale çalışmaları
1. **IET JoPE:** Special issue submit edildi.
2. **IET JoE:** Yayınlanmaya hazır.
3. **ECCE 2019:** Kabul edildi. Full-paper için planlama yapıldı.
4. [**Ufuktaki Konferanslar**](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)

##### Tez çalışmaları
1. **Outline:** Tamamlanacak.
2. **TİK:** Rapor yazıldı, gönderildi. Sunum yapıldı.

##### Proje, rapor, satın almalar
1. **Bütçe:** Avans çekildi. Aktarmalar yapılacak.

________


### Nisan 2019

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı testi:** Flyback yük altında çalıştı (30W). Noise problemi var, bakılacak. PWM bufferlara bakılıyor, 3 tanesi kaldı. ADC_REF bufferları düzeltildi.
  * **Kontrol DSP yazılımı:** Yazılım kontrol kartında çalışıyor. PWM, enable ve interrupt yapıldı. ADC çalışırıldı. Timingler ayarlandı. PI controller, park, clarke ve inverse'leri yazıldı. EQEP'e bakılıyor.
  * **Versiyon 1.3 gate driver kartı:** 2 tane dizildi. Bir karta temel testler yapıldı. DPT yapıldı. İnverter testleri yapıldı (300V-8A-2kW). Akım ölçümleri test edilmedi.
2. GaN Gardaşları
  * **Karakterizasyon kartı:** Layout tasarımı için toplantı yapılacak.
3. V.1. Motor
  * **Test düzeneği:** Hazırlandı.
  * **Ölçüm testleri** Direnç, inductance testi yapıldı.
  * **Jeneratör mod:** Endüklenen gerilimlere bakıldı. Tüm sargılardan data alındı. Yükle test ediliyor.

##### Makale çalışmaları
1. **ACEMP 2019:** Nope.
2. [**Ufuktaki Konferanslar**](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)
3. **IET JoE:** İstenen düzeltmeler gönderildi.
4. **IET JoPE:** Special issue için outline çıkarıldı.

##### Tez çalışmaları
1. **Outline:** Tamamlanacak.
2. **Modüler motor sürücü:** Dengesizlikler üzerine simulasyonlara devam edilecek.

##### Proje, rapor, satın almalar
1. BAP
  * **Final Raporu:** Teslim edildi.
2. 3501
  * **2. Gelişme Raporu**: Teslim edildi.
  * **Bütçe:** Kalan bütçeye bakıldı. Yeni avans çekilecek.

________

### Mart 2019

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı testleri:** Tamamlandı. Flyback'in yük altında testine tekrar bakılacak.
  * **Kontrol DSP yazılımı:** Temel LED yakma yazılımı hazırlandı, çalıştırıldı. Yazılım geliştirilecek.
  * **Versiyon 1.2 gate driver kartı:** Testlere devam edildi. False turn-on anına bakıldı. (Bkz: Test günlükleri)
  * **Versiyon 1.3 gate driver kartı:** Tamamlandı. Üretime gönderildi. Dizgi gelecek ay.
2. GaN Gardaşları
  * **Karakterizasyon kartı:** Layout tasarımı için toplantı yapılacak
3. V.1. Motor
  * **Test düzeneği:** Hazırlanacak.
  * **Ölçüm testleri** Yapılacak.
  * **Jeneratör mod:** Testlere başlanacak. Endüklenen gerilimlere bakılacak.

##### Makale çalışmaları
1. **PEDS 2019:** Kabul edildi. Final paper submit edildi.
2. [**Ufuktaki Konferanslar**](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)

##### Tez çalışmaları
1. **Outline:** Tamamlanacak.
2. **Modüler motor sürücü:** Dengesizlikler üzerine simulasyonlara devam edilecek.

##### Proje, rapor, satın almalar
1. BAP
  * **3.Gelişme Raporu** Teslim edilecek.
2. 3501
  * **2. Gelişme Raporu**: Outline çıkarıldı. Yazımına başlandı.
  * **Bütçe:** Kalan bütçeye bakıldı. Yeni avans çekilecek.

________

### Şubat 2019

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı test planı yapıldı.**
  * **Kontrol kartı testlerine başlandı. Flyback çalıştı ve patladı. Hata tespit edildi. Malzeme sipariş edildi. [Malzeme listesi](https://docs.google.com/spreadsheets/d/1yYd4jG9k6lppbEI8Sx3rW8ZVwk8tipui_LQqaIk5rZo/edit#gid=0)**
  * **Güç kartı 1 tane dizilecek => 3-faz Inverter testi yapılacak => Yeni kart tasarımı yapılacak**
  * **Full-bridge ile termal test yapıldı. DPT'ye geri dönüldü (20 Ohm)**
  * **DPT testleri ile farklı Ron değerlerinde farklı noktalardaki osilasyonlara bakılıyor**
  * **Versiyon 1.2 gate driver kartına başlandı**
2. GaN Gardaşları
  * PCB layout tasarımı
3. V.1. Motor
  * **Montaj yapıldı**
4. V.1. Mekanik
  * **Mekanik parçaların üretimi yapıldı**
5. V.1. Soğutucu
  * **Heat sink uzunluğu gözden geçirildi. Şimdilik bu şekilde kalacak. Yeni PCB'de değerlendirilecek.**

##### Makale çalışmaları
1. **ECCE 2019: Gönderildi**
2. **PEDS 2019: Kabul edildi. Final paper 15 Mart**
2. [Ufuktaki Konferanslar](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)
3. **Dergi (MDPI Electronics) => Yeni GaN kartı için ertelendi**

##### Tez çalışmaları
1. Outline tamamlanacak
2. Modüler motor sürücü dengesizlikleri üzerine simulasyonlar
3. **Loss hesabı yapıldı**

##### Proje, rapor, satın almalar
1. 3501
  * Avans kapatılacak
  * [Malzeme listesi](https://docs.google.com/spreadsheets/d/1yYd4jG9k6lppbEI8Sx3rW8ZVwk8tipui_LQqaIk5rZo/edit#gid=0)
2. BAP
  * **3.Gelişme Raporu Taslağı oluşturuldu**
  * 3.Gelişme Raporu teslim edilecek.

________


### Ocak 2019

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı 1 tane dizildi (+2 DSP)**
  * **DPT testleri tamamlandı**
  * **Inverter testi GaN yavaşlatılarak yapıldı. 275V'ta 10 sn sonra yandı.**
2. GaN Gardaşları
  * **PCB layout tasarımı devam**
3. V.1. Motor
  * **Sarımlar yapıldı.**
4. V.1. Mekanik
  * **Mekanik parçaların üretimi yapılıyor.**
  * **Kasa kedildi.**
5. V.1. Soğutucu

##### Makale çalışmaları
1. **ECCE 2019: "IMMD PCB effect of parasitic inductances" üzerine yazıldı (Digest, 15 Ocak), [tık](http://www.ieee-ecce.org/2019/).**
2. [Ufuktaki Konferanslar](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)
3. **Dergi (MDPI Electronics): Abstract**

##### Tez çalışmaları
1. **Modüler motor sürücü dengesizlikleri inceleniyor**

##### Proje, rapor, satın almalar
1. 3501
  * **Hizmet (avans)**
  * **Sarf (avans)**
  * Avans kapatılacak
2. BAP
  * 3.Gelişme Raporu (Mart 2018-Eylül 2018)

________

### Aralık 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * Kontrol kartı 1 tane dizilecek (+2 DSP)
  * Güç kartı 3 tane daha dizilecek
  * **Güç kartı overshoot problemi üzerine simulasyon yapıldı, beraberinde DPT testi yapıldı.**
  * **Güç kartı tüm fazlara DPT yapıldı, C fazı 225 V'ta patlıyor. Problem çözülemedi**
  * **Güç kartı soğutucu ile yük altında teste devam ediliyor (bkz: [Test](https://github.com/mesutto/IMMD/tree/master/Prototype/Test))**
2. GaN Gardaşları
  * PCB şematik tasarımı tamamlanacak
  * PCB layout tasarımına başlanacak
3. V.1. Motor
  * **Üretim planı yapıldı**
  * **Montaj planı yapıldı**
  * **Stator sarımı yapıldı**
4. V.1. Mekanik
  * **Mekanik parçaların üretimi yapılıyor (önce çizimler son haline gelecek)**
  * **Kasa uzunluğu belirlendi**
  * Kasa kesilecek
5. V.1. Soğutucu
  * **Güç kartına göre soğutucu simulasyonu yapıldı**
  * Heat sink uzunluğu gözden geçirilecek

##### Makale çalışmaları
1. **PEDS 2019: Abstract submit edildi**
2. **ECCE 2019: "IMMD PCB effect of parasitic inductances" üzerine yazılacak (Digest, 15 Ocak), [tık](http://www.ieee-ecce.org/2019/).**
3. [Ufuktaki Konferanslar](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)

##### Tez çalışmaları
1. **TİK raporu verildi**
2. **TİK sunumu hazırlandı**
3. TİK jürisi
4. Outline tamamlanacak
5. Tezin yazımına başlanacak
6. Fault durumları ve tespiti üzerine simulasyonlar
7. **Fault tolerance, topologies vb. üzerine okumalar ve derlemeler (bkz. [Sunum](https://github.com/mesutto/IMMD/blob/master/Literature/immd_ver2_research.pptx))**
8. Versiyon-2 parametreleri geliştirilecek (bkz: [Ver.2](https://github.com/mesutto/IMMD/tree/master/Project/3501/IMMD%20Version%202.0))
9. GaN ile ilgili çalışmalar
  * Matematik modelinin half-bridge şeklinde geliştirilmesi
  * Loss modellemesi **???**
  * PCB'ler arası endüktanslar çıkarılacak
  * Endüktansların 4 modülde etkileri incelenecek

##### Proje, rapor, satın almalar
1. 3501
  * Hizmetten aktarım yapılacak (avans)
  * Avans kapatılacak
2. BAP
  * 3.Gelişme Raporu (Mart 2018-Eylül 2018)

________

### Kasım 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı üretildi**
  * **Kontrol kartı BOM gözden geçirildi ve sipariş listesi oluşturuldu**
  * **Güç kartı soğutucu ile yük altında test ediliyor (bkz: [Test](https://github.com/mesutto/IMMD/tree/master/Prototype/Test))**
2. GaN Gardaşları
  * **PCB şematik tasarımı toplantısı yapıldı**
3. V.1. Motor
  * Montaj planı yapılacak
  * Sarım planı yapılacak
4. V.1. Mekanik
  * Tüm mekanik parçaların üretimi yapılacak
  * Kasa kesilecek (uzunluk belirlenmeli)
5. V.1. Soğutucu
  * Güç kartına göre soğutucu simulasyonu yapılacak???
  * **Heat sink delikleri açıldı**
  * Heat sinkte termal test ???

##### Makale çalışmaları
1. **EPE 2019:** GaN matematik modeli yazılabilir (3-5 page Synopsis, 15 Aralık)
2. **PEDS 2019:** Fault Analysis and Comparison of Modular PMSMs (<=3 page extended summary, 6 aralık): **Outline çıkarıldı**
3. **ECCE 2019:** IMMD PCB effect of parasitic inductances (Abstract, 15 Ocak) [Konferanslar](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)

##### Tez çalışmaları
1. TİK raporu hazırlanıp gönderilecek
2. **IMMD ile ilgili pratik sorunlar üzerine simulasyon çalışmaları yapıldı**
3. **Fault tolerance, topologies vs. üzerine okumalar (bkz. sunum)**
4. **Versiyon-2 parametreleri ve uygulama üzerine çalışıldı** (bkz: [Ver.2](https://github.com/mesutto/IMMD/tree/master/Project/3501/IMMD%20Version%202.0))
5. GaN ile ilgili çalışmalar
  * **Matematik modeli tamamlandı. Inverter devresi kuruluyor**
  * Loss konusunun ilerletilmesi (belki EPE veya ECCE'ye yazılabilir)
  * **Inductance'lar çıkarıldı**
  * **Inductance'ların tek modülde etkileri incelendi**

##### Proje, rapor, satın almalar
1. 3501
  * Hizmetten aktarım yapılacak (avans)
  * **Eksik malzemelerin siparişi verildi (avans)**
  * [Eksik malzemeler burada](https://docs.google.com/spreadsheets/d/1sfCz6HN4rGlijo-bTDD3Y9WSTPjLGswah7e4vqFpGgs/edit#gid=0)
2. BAP
  * 3. Gelişme Raporu (Mart 2018-Eylül 2018)

________


### Ekim 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartına son eklemeler tamamlandı**
  * **Güç kartı fonksiyonel testleri yapıldı**
2. GaN Gardaşları
  * **PCB şematik tasarımı devam ediyor**
  * **Akım koruması devresi tamamlandı**
3. V.1. Motor

4. V.1. Mekanik
  * **Kasaya göre mekanik parçalara son rötuşlar verildi**
5. V.1. Soğutucu
  * **Heat sink çizimi son haline getirildi**
  * **Heat sink kesildi**
  * **Heat sinkte termal teste devam edildi**

##### Makale çalışmaları
1. **Dergi makalesi için bir outline çıkarıldı**
2. **EPE 2019:** GaN matematik modeli yazılabilir (3-5 page Synopsis, 15 Kasım)
3. **PEDS 2019:** Fault Analysis anc Comparison of Modular PMSMs (<=3 page extended summary, 15 Kasım)
4. **ECCE 2019:** GaN (Abstract, 15 Ocak) [Konferanslar](https://github.com/mesutto/IMMD/blob/master/conference%20list%20short.md)

##### Tez çalışmaları
1. **IMMD ile ilgili pratik sorunlar üzerine çalışmalar (dengesizlik vb.) devam edildi**
2. **Fault tolerance, topologies vs. üzerine okumalara devam edildi (bkz. sunum)**
3. **Versiyon-2 parametreleri belirlenmesi üzerine çalışıldı**
4. GaN ile ilgili çalışmalar
  * **Matematik modeli ilerletildi**
  * **Inductance çalışmalarının ilerletildi**

##### Proje, rapor, satın almalar
1. 3501
  * **Güç kartları 2 tane dizildi**
  * **3501 raporu tamamlandı, gönderildi**
  * **Sarf avans kapatıldı**
  * **Hizmet + sarf avans çekildi**
  * [Eksik malzemeler burada](https://docs.google.com/spreadsheets/d/1sfCz6HN4rGlijo-bTDD3Y9WSTPjLGswah7e4vqFpGgs/edit#gid=0)

________


### Eylül 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı layout tasarımı tamamlandı**
  * **Güç kartı yeniden üretildi, stencil üretildi**
2. GaN Gardaşları
  * **PCB mimari tasarımı yapılıyor**
  * **PCB şematik tasarımına başlandı**
3. V.1. Motor
  * Montaj planı yapılacak
  * Sarım planı yapılacak
4. V.1. Mekanik
  * **Tüm parçaların çizim ortamında birleştirildi**
  * **Kasa bulundu, tedarik ediliyor**
5. V.1. Soğutucu
  * Heat sink delikleri açılacak
  * Heat sinkte termal teste devam edilecek

##### Makale çalışmaları
1. PWM makalesi
  * İncelenecek tekniklerin belirlenmesi için makale okunuyor
  * MATLAB'ta simulasyon ortamının bitirilmesi. (3-level bitirilecek)
2. [Konferanslar](www.google.com)

##### Tez çalışmaları
1. **Aerospace applications, integration, fault tolerant drives and motors konularında makale okunuyor**
2. **Versiyon 2 IMMD için isterler, parametreler ve temel tasarım kararları (first draft) çıkarıldı**
3. **IMMD ile ilgili pratik sorunlar (circulating currents, voltage balancing, fault detection vb.) üzerine çalışmalar yapılıyor**
4. GaN ile ilgili çalışmalar
  * **Modelleme (matematiksel) çalıştı**
  * Loss konusunun ilerletilmesi
  * **Inductance via FEA çalışmaları devam ediyor**

##### Proje, rapor, satın almalar
1. 3501
  * **Güç kartı üretildi**
  * Kontrol kartı üretilecek
  * **Stencil üretildi**
  * **3501 raporu yazıldı**
  * Sarf avans kapatılacak
  * [Eksik malzemeler burada](https://docs.google.com/spreadsheets/d/1sfCz6HN4rGlijo-bTDD3Y9WSTPjLGswah7e4vqFpGgs/edit#gid=0)

________


### Ağustos 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı layout tasarımı ilerletildi**
  * **Güç kartı fonksiyonel testleri tamamlandı**
  * **Güç kartı layout tasarımı yeniden düzenlendi**
2. GaN EVM
  * Yeni akım ölçüm aparatı alınacak
  * Vaktinde gelirse ölçümler devam ettirilecek
3. GaN Gardaşları
  * PCB mimari tasarımı yapılacak
  * PCB şematik tasarımına başlanacak
4. V.1. Motor
  * Montaj planı yapılacak
  * Sarım planı yapılacak
5. V.1. Mekanik
  * Tüm parçaların çizim ortamında birleşmesi
  * Kasa seçimi yapılacak
6. V.1. Soğutucu
  * Heat sink delikleri açılacak
  * **Heat sink termal teste başlandı**

##### Makale çalışmaları
1. ICEM 2018
  * **Poster hazırlandı**
2. PEMC 2018
  * **Sunum hazırlandı (HS)**
3. EPE 2018
  * Poster hazırlanacak (FK)
4. PWM makalesi
  * İncelenecek tekniklerin belirlenmesi için makale okunuyor
  * MATLAB'ta simulasyon ortamının bitirilmesi. (3-level bitirilecek)
5. GRW 2018
  * **Poster hazırlandı (FK)**
6. PEMD 2018
  * **Journal için çalışmalar tamamlandı**

##### Tez çalışmaları
1. **Aerospace applications, integration, fault tolerant drives and motors konularında makale okunuyor**
2. Versiyon 2 IMMD için isterler, parametreler ve temel tasarım kararları (first draft)
3. IMMD ile ilgili pratik sorunlar (circulating currents, voltage balancing, fault detection vb.) üzerine çalışmalar yapılacak
3. **PhD tezin içeriği detaylandırıldı**
3. GaN ile ilgili çalışmalar
  * **Modelleme (matematiksel) başlandı**
  * Loss konusunun ilerletilmesi
  * **Akım ölçümü konularında literatür tarandı**
  * **Inductance via FEA çalışılıyor**

##### Proje, rapor, satın almalar
1. 3501
  * **Sarf için yeni avans alındı**
  * **Sarf malzemeler sipariş edildi**
  * Kontrol kartı üretilecek
  * Güç kartı üretilecek
  * 3501 rapor taslağı oluşturulacak

https://docs.google.com/spreadsheets/d/1sfCz6HN4rGlijo-bTDD3Y9WSTPjLGswah7e4vqFpGgs/edit#gid=0

________


### Temmuz 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * **Kontrol kartı şematik tasarımın tamamlandı**
  * **Kontrol kartı layout tasarımına başlandı**
  * **Güç kartı için laba dizgi ve test setupları kuruldu**
  * **Güç kartı dizgisi yapıldı**
  * Güç kartı test & debug yapılacak
  * **Konektör ve termal izolatör seçildi**
2. GaN EVM
  * Yeni akım ölçüm aparatı alınacak
  * Vaktinde gelirse ölçümler devam ettirilecek
3. Yeni GaN'lı devre
  * **Planlama yapıldı. Parametreler tartışıldı.**
  * PCB mimari tasarımı yapılacak
4. V.1. Motor
  * Montaj planı yapılacak
  * Sarım planı yapılacak
5. V.1. Mekanik
  * **Rotor çizimi yapıldı**
  * **Şaft çizimi yapıldı**
  * **Ön kapak çizimi yapıldı**
  * **Arka kapak çizimi yapıldı**
  * **Kasa tedarik edilecek**
  * **Rulman seçimi yapıldı**
  * **Tüm parçaların çizim ortamında birleşmesi kısmen yapıldı**
  * **Encoder çizimi yapıldı**
6. V.1. Soğutucu
  * **Heat sink çizimi yapıldı**
  * **Heat sink kesimi yapıldı**
  * HEat sink delikleri açılacak

##### Makale çalışmaları
1. ICEM 2018
  * Registration yapılacak
2. PWM makalesi
  * İncelenecek tekniklerin belirlenmesi için makale okunuyor
  * MATLAB'ta simulasyon ortamının bitirilmesi: **3-level bitirilecek**
3. GRW 2018
  * **Abstract FK: GaN**
4. Trans. on Education gündemimizde yok

##### Tez çalışmaları
1. **Aerospace applications, integration, fault tolerant drives and motors konularında makale okunuyor**
2. **PhD tezin kabaca outline'ı çıkarıldı**
3. GaN ile ilgili çalışmalar
  * Modelleme (matematiksel) başlanacak
  * Loss konusunun ilerletilmesi
  * Akım ölçümü ile ilgili araştırma yapılıyor

##### Proje, rapor, satın almalar
1. 3501
  * Sarf için yeni avans alınacak. **Malzeme listesi çıkarıldı.** https://docs.google.com/spreadsheets/d/1sfCz6HN4rGlijo-bTDD3Y9WSTPjLGswah7e4vqFpGgs/edit#gid=0
    * **Teçhizat prosedürleri tamamlandı**

________

### Haziran 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * Kontrol kartı (DSP) şematik tasarımın tamamlanması: **Devam ediyor.**
  * Kontrol kartı (DSP + flyback) layout tasarımına başlanması: **Fiziksel yapı tasarlandı. Devam ediyor.**
  * Güç kartı (gate drive) PCB gözden geçirme: **OK**
  * Güç kartı (gate drive) PCB üretimi: **OK**
  * Encoder seçimi: **OK**
2. GaN EVM
  * Test sonuçlarının simulasyon ile karşılaştırılıp yorumlanması: **OK**
3. V.1. Motor
  * Mıknatıs boyutlandırma ve üretime başlanması: **OK**
  * Rotor tasarım güncelleme ve üretime başlanması: **Rotor için haber bekleniyor**
4. V.1. Mekanik
  * Solid eğitimi: **OK, Güzel oldu :)**
  * Mekanik tasarımın son haline gelmesi: **Bireysel tasarımların bitmesi bekleniyor**
  * Tüm parçaların çizim ortamında birleşmesi: **Bireysel tasarımların bitmesi bekleniyor**
5. V.1. Soğutucu
  * Heat sink boyutlandırma ve malzeme seçilmesi: **OK**
  * Heat sink çizimi (solid): **Devam ediyor.**
  * Heat sink işlenmesi (kesilmesi): **Çizimden sonra kesilecek**

##### Makale çalışmaları
1. EPE 2018
  * Toplanan dataların yorumlanması ve makaleye girdi oluşturulması: **OK**
  * Makalenin yazılması ve submission: **OK**
2. ICEM 2018 (Kabul)
  * Makalenin yazımı (Camera ready): **OK**
3. PEMC 2018 (Kabul)
  * Kayıp hesabı hatalarının giderilmesi: **OK**
  * Verilerin yorumlanması: **OK**
  * Makalenin yazımı (Camera ready) ve submission: **OK**
4. PWM makalesi
  * İncelenecek tekniklerin belirlenmesi: **Makale okunacak**
  * MATLAB'ta simulasyon ortamının bitirilmesi: **3-level bitirilecek**
5. GaN'larda loss analizi konusunda teorik çalışmalar: **ECCE makalesi ilerletilecek**

##### Tez çalışmaları
1. Literatür
  * Literatür sonucu teorik olarak odaklanılacak konuların belirlenmesi: **Tezin araştırma odakları belirlenecek**
2. Tez
  * Tez yazımına başlanması (latex): **Latex template'te tez başlığı atıldı :)**

##### Proje, rapor, satın almalar
1. 3501
  * Teçhizatların alınması: **OK**
  * Sarf malzemelerin alınması: **OK**
  * Motor üretimi (hizmet-avans): **OK**
________

### Mayıs 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * Kontrol kartı (DSP) şematik tasarımın tamamlanması: **Ertelendi**
  * Güç kartı layout tasarımının tamamlanması: **OK**
  * Konektör ve izolatör seçimi: **OK**
  * Kontrol kartı layout tasarımına başlanması: **Ertelendi**
  * Güç kartı modüllerinin üretimine başlanması: **Layout kontrol ediliyor**
  * Encoder seçimi ve tedariki: **Ertelendi**
2. GaN EVM
  * Double pulse test devresinin kurulması: **OK**
  * Double pulse testlere başlanması: **OK**
  * Test sonuçlarının simulasyon ile karşılaştırılıp yorumlanması: **Ertelendi**
3. V.1. Motor ve mekanik
  * Motor tasarımı (270mm'ye göre tasarım bitirilecek): **OK**
  * Mekanik tasarımın son haline gelmesi: **Ertelendi (Solid edğitimi bekleniyor)**
  * Tüm parçaların çizim ortamında birleşmesi (Solid): **Ertelendi (Solid edğitimi bekleniyor)**
  * Motor üretimine başlanması: **OK**
  * Heat sink boyutlandırma ve malzeme seçilmesi: **Ertelendi**
  * Heat sink işlenmesi (kesilmesi): **Ertelendi**

##### Makale çalışmaları
1. EPE 2018
  * Toplanan dataların yorumlanması ve makaleye girdi oluşturulması:  **Ertelendi**
  * Makalenin yazılması ve submission: **Ertelendi**
2. ICEM 2018
  * Review gelirse (ve accept gelirse :)) güncelleştirmelerin yapılması: **Review henüz gelmedi**
3. PEMC 2018 (Kabul)
  * Makale düzeltme planı: **OK**
  * Yeni verilerin toplanması: **OK**
  * Verilerin yorumlanması ve makalenin yazımı (Camera ready): **Bazı hatalar gideriliyor**
4. PWM makalesi
  * Makale taslağı oluşturulması: **OK**
  * İncelenecek tekniklerin belirlenmesi: **Ertelendi**
  * MATLAB'ta simulasyon ortamı kurulması: **OK, 3-level eksik**
5. GaN'larda loss analizi konusunda teorik çalışmalar (ECCE makalesi): **Ertelendi**
6. ICEM için review: 6 Mayıs: **OK**
7. Ulusal dergi (Fırat Üni): 6 Mayıs: **OK**

##### Tez çalışmaları
1. Literatür
  * Literatür sonucu teorik olarak odaklanılacak konuların belirlenmesi: **Ertelendi**
2. Tez İzleme Komitesi
  * Sunum hazırlama: **OK**
  * Sunum ve feedback: **OK**

##### Proje, rapor, satın alma
1. BAP
  * Gelişme raporunun yazılması ve teslim edilmesi: **OK**
  * Sarf bütçesinin harcanması: **OK**
2. 3501
  * Teçhizatların alınması: **Teklif geldi, malzeme seçiliyor**
  * Hizmet alımı içni avans: **OK**
  * Sarf listesi çıkarılması: **PCB için çıkarıldı**

________

### Nisan 2018

##### Tasarım - donanım çalışmaları
1. V.1. PCB
  * Güç kartı şematik tasarımın tamamlanması: **OK**
  * Kontrol kartı şematik tasarımın tamamlanması: **Flyback OK, DSP kartı tasarlanacak**
  * Boyutlandırma, yerleşim, komponent seçimi vb. çalışmaların tamamlanması: **OK, konektörler, izolatör seçilecek**
  * Güç kartı layout tasarımı: **OK, son boyut bekleniyor ona göre güncelleme yapılacak**
2. GaN EVM
  * Yüksek gerilimde ve frekansta test yapılması: **OK, 400V, 10kHz**
  * Test setupının iyileştirilmesi, probing: **OK**
  * R ve L yüklerin testi: **OK**
  * Yük altında test: **OK, 400V, 8A**
3. V.1. Motor
  * Motor tasarımının yenilenmesi (240 vs 270):
  * Mekanik tasarımın son haline gelmesi:
  * Tüm parçaların çizim ortamında birleşmesi:
  * Üretim prosedürünün netleştirilmesi (kim nereyi nasıl üretecek): **Doküman oluşturulacak**
  * Üretim için toplam maliyet çıkarılması

##### Makale çalışmaları
1. PEMD 2018
  * Sunumun prova ile son haline gelmesi: **OK**
  * Konferansta sunum yapılması (14-22 Nisan): **OK :)**
2. ICEM 2018
  * Simulasyonların ve hesaplamaların sonlandırılması: **OK**
  * Sonuçların makaleye eklenmesi, discussion ve conclusion yazılması: **OK**
  * Submittion (Deadline: 15 Nisan): **OK**
3. PWM makalesi
  * Makale taslağı oluşturulması
  * İncelenecek tekniklerin belirlenmesi
  * MATLAB'ta simulasyon ortamı kurulması
4. EPE 2018
  * Makale outline çıkarılması

##### Tez çalışmaları
1. Literatür
  * Detaylı literatür çalışmasının sunuma dönüştürülmesi: **OK**
  * Literatür sonucu teorik olarak odaklanılacak konuların belirlenmesi

##### Proje, rapor, satın alma
1. BAP
  * Gelişme raporunun yazılması ve teslim edilmesi
  * Sarf bütçesinin harcanması
2. 3501
  * Teçhizatların alınması

##### Research League
1. Yeni dönem starcılar
  * Rubrik oluşturulması: **OK**
  * Sunumlar ve değerlendirme: **OK**
  * Yeni ekibe proje atanması: **OK**
