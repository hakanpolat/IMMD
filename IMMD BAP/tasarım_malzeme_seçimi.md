### Bu dökümanda malzeme seçimleri, tasarım değerleri, örnek malzemeler vb. yer alacaktır.

#### Tanımlar
* m = faz sayısı
* p = kutup sayısı
* n = kutup sayısı
* Ns = stator slot sayısı
* pr = rotor kutup sayısı

#### PCBler
1. m x n x Güç katı devresi
2. n x Slave kontrol devresi
3. 1 x Master kontrol devresi
4. n x 1 x Ölçüm devresi
5. 1 x Güç kaynağı devresi
6. 1 x Rectifier devresi (filtre dahil)

**Çizim eklenecek**


#### Rectifier tarafı
* Tahmin edilen akım gerelim değerleri: 600V, 8A
* Gerekli akım gerelim değerleri: 800V, 20A
* **Doğrulamak için benzetim yapılacak**
* Örnek ürünler:
  * [Vishay VS-26MT100](http://tr.farnell.com/vishay/vs-26mt100/bridge-rectifier-25a-3ph/dp/9098550)
  * [SEMIKRON SKD2508](http://tr.farnell.com/semikron/skd2508/bridge-rectifier-20a-800v-3ph/dp/9401830)
  * [VISHAY VS-26MT80](http://tr.farnell.com/vishay/vs-26mt80/bridge-rectifier-25a-3ph/dp/9098542)
  * Paket büyüklükleri genelde 28.5 mm, yükseklik bacak hariç 10 mm.

#### DC Bara
* Her güç katı kartı üzerinde kendine ait kondansatörler olacak. DC barada (tek kart) ortak bir kondansatör olabilir.

#### Motor sürücü
* Kaç mödül, kaç seri, kaç parallel?
* Hangi GaN? 200V EPC or 600V transphorm?

**Manufacturers:**
* Cascode GaN: **Transphorm**
* Enhancement mode GaN: **EPC**, **GaN systems**


**Fujitsu webshop**: Burada EVM yok ama device var (Transphorm)

http://shop.feeu.com/epages/es966226.sf/en_GB/?ObjectPath=/Shops/es966226/Categories/Category1

**Transphorm Sales**

http://www.fujitsu.com/tr/

+90 0 212 557 18 81


**EPC Sales Representative**

ISMOSIS TURKEY:

Tel: +90 216 5450025

Email: infoT@ismosys.com


**GaN Systems Sales** (mailde öneriler siteler)

http://www2.mouser.com/search/refine.aspx?N=4285500034

http://www.ecomal.com/index.php?id=2&L=3

http://www.richardsonrfpd.com/Pages/home.aspx

**Digikey Ürünleri**
1. https://www.digikey.com/product-detail/en/transphorm/TDPV1000E0C1-KIT/TDPV1000E0C1-KIT-ND/6207312
2. https://www.digikey.com/product-detail/en/transphorm/TDHBG2500P100-KIT/TDHBG2500P100-KIT-ND/6605351
3. https://www.digikey.com/product-detail/en/epc/EPC9101/917-1024-ND/2749209
4. https://www.digikey.com/product-detail/en/epc/EPC9118/917-1073-ND/4989143
5. https://www.digikey.com/product-detail/en/epc/EPC9107/917-1033-ND/4071532
6. https://www.digikey.com/product-detail/en/epc/EPC9102/917-1025-ND/2797428
7. https://www.digikey.com/product-detail/en/epc/EPC9115/917-1095-ND/513835

**Digikey distributor**

gizem.tekin@ekom-ltd.com

EKOM Elektronik Ltd.

T: +90 212 590 9715 (pbx)

http://www.ekom-ltd.com

**Mouser Distributor**

ROM Elektronik San ve Tic. Sti

Esatpaşa Mah. Kalebaşı Sokak No: 20 34704
Ataşehir İstanbul

Tel: 0216 492 85 50

E-posta: info@romelektronik.com

http://www.romelektronik.com

tr.mouser@romelektronik.com

**Farnell Distributor**

Yıldırım Elektronik

yasin@yildirimelektronik.com

**Mouser ürünleri**
1. http://www.mouser.com.tr/ProductDetail/GaN-Systems/GS665MB-EVB/?qs=sGAEpiMZZMtJijNuLr2%252bGS%2f3uRRSUPt70Nqiw7kqmilbcq%252bzpg3iHg%3d%3d
2. http://www.mouser.com.tr/ProductDetail/GaN-Systems/GS66508B-EVBDB/?qs=sGAEpiMZZMtJijNuLr2%252bGS%2f3uRRSUPt7q8BEuR5%252bWc36ai6VwhXqMQ%3d%3d
3. http://www.mouser.com.tr/ProductDetail/GaN-Systems/GS66508T-EVBDB/?qs=sGAEpiMZZMtJijNuLr2%252bGS%2f3uRRSUPt76rH3g1Fbtf6Rss%252b8qCJsew%3d%3d
4. http://www.mouser.com.tr/ProductDetail/GaN-Systems/GS61008P-EVBBK/?qs=sGAEpiMZZMtJijNuLr2%252bGS%2f3uRRSUPt7MuQEEcmVdw3cLwosjl1%252bvg%3d%3d
5. http://www.mouser.com.tr/ProductDetail/GaN-Systems/GS66504B-EVBDB/?qs=sGAEpiMZZMtJijNuLr2%252bGS%2f3uRRSUPt77zkRkNILdMZ5%252bEhZs%252bJbmQ%3d%3d

**Farnell ürünleri**

No products related to GaN.


#### Motor
[Frameless motor catalog from Kollmorgen](http://www.kollmorgen.com/en-us/products/motors/direct-drive/kbm-series-frameless/_literature/kbm-selection-guide-en-us_revg/)

Example motor (Page-44):
- KBM(S)-4502B
- 10 pole
- 7.2kW continuous output power
- 2350 rpm
- 180 Vrms/kRPM (423V at rated speed)
- stator length: 141 mm
- rotor length: 126 mm
- outer diameter: 190 mm
- inner diameter: 85 mm

[Installation of frameless motors (video)](http://www.kollmorgen.com/en-us/products/motors/direct-drive/kbm-series-frameless/)

[Webinar about frameless motor technology](https://www.youtube.com/watch?v=L2XrGfEYa2w)

*  **Motor için üreticiler**
  * [Kollmorgen](http://www.kollmorgen.com/en-us/products/motors/direct-drive/kbm-series-frameless/_literature/kbm-selection-guide-en-us_revg/)
  * [BEI KIMCO](http://www.beikimco.com/motor-products/brushless-dc/BLDC-brushless-frameless-parts-kit): All are low voltage.
  * [ARC SYSTEMS](http://www.arcsystemsinc.com/category/115/Brushless.html?sort=name&size=10&page=3): Most of them are low voltage. Power ratings are very low.
  * [Allied Motion](http://catalog.alliedmotion.com/ecatalog/frameless-quantum-brushless-servo-motors/si): There are a few motors suitable for us.
  * [Electromate](https://www.electromate.com/assets/catalog-library/pdfs/applimotion/Applimotion_UTS_Motor_kits_Datasheet.pdf): Something called slotless zero cogging motor kit, don't know what.
  * [Electromate-2](https://www.electromate.com/assets/catalog-library/pdfs/applimotion/Applimotion_ULT_Motor_Kits_datasheet.pdf): BLDC motor kits.
  * [Aerotech](https://www.aerotech.com/product-catalog/motors/rotary-motors/s-series.aspx?p=%2fproduct-catalog%2fmotors%2frotary-motors.aspx%3ftype%3dFrameless): Ratings below 1 kW - frameless.
  * [Koford](http://www.koford.com/129.pdf): 160V - 4.5kW frameless BLDC is avaiable
  * [US MOTION](http://www.usmotion.com/custom-servo-motors/custom-frameless-motors/): Frameless, "wound conductor or pcb stator" option is interesting.
  * [Parker Motion](http://www.parkermotion.com/pdfs/bayside_cat/07%20Frameless%20Motors%20&%20Gearmotors.pdf): (Continuous) Torque ratings up to 90Nm.
  * [Moog](http://www.moog.com/products/motors-servomotors/brushless-motors/inside-rotor-brushless-dc-motors/frameless.html): Does not give any specifications !!!
  * [Mclennan - HT series](http://www.mclennan.co.uk/product/ht-series-frameless-torque-motors): 24V and 100V options. Peak torque up to 25 Nm.
  * [Mclennan - Megaflux](http://www.mclennan.co.uk/product/megaflux-frameless-torque-motors): There are a lot of suitable selection.


* distributed or concentrated?
* Üretim için gereken altyapı araştırılacak
* Hazır frameless motorlarda oluk sayılarına bakılacak (3D models)
* Kollmorgen'a mail atılacak (alttaki seçenekler için)
* Winding konfigurasyonları araştırılacak
* Dengesiz çalışmanın önüne geçmek için konfigürasyona dikkat etmek lazım

Üç seçenek üzerinde duruluyor:
1. Frameless seçip yeniden sardırmak veya sargısız sipariş etmek, rotoru da birlikte sipariş etmek, kendimiz montajını yapmak
2. Statoru laminasyon ile kendimiz üretmek, rotoru sipariş etmek, kendimiz montajını yapmak
3. Statoru da rotoru da kendimiz üretmek, kendimiz montajını yapmak


#### İşlemci (MCU)
* Master/slave yapılacak mı?
* Olursa master ayrı devrede mi olacak?

#### Kontrol ve ölçüm devresi

#### Güç kaynağı

#### Soğutucu

#### Frame / Mekanik
