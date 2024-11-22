# Objektinis-programavimas
## Programos aprašymas <br/>
Ši programa leidžia vartotojams įvesti arba importuoti studentų duomenis, įskaitant vardą, pavardę, namų darbų rezultatus ir egzamino įvertinimus. Galutiniai rezultatai apskaičiuojami pagal formulę:

*Galutinis balas = 0,4 × namų darbų vidurkis + 0,6 × egzamino įvertinimas*<a/>

Vartotojai gali pasirinkti, ar namų darbų rezultatus skaičiuoti naudojant medianą, ar vidurkį. Rezultatai su studento informacija ir galutiniu balu gali būti išvedami į naują failą arba rodomi terminale.

**Išsimčių valdymas:**
* Klausimuose, kuriuose reikalaujama vartotojo pasirinkti vieną iš dviejų variantų yra naudojama try and catch norint apsaugoti nuo neteisingų įvedimų ir taip pat sistemos lūžimo, jeigu būtų įvesta raidė
* Norint įvesti namų darbų ar egzamino pažymį vartotojas yra apribojamas sveikaisiais skaičiais nuo 1 iki 10
* Nuskaitant failą yra tikrinama ar failas atsidaro, ar nuskaitytoje eilutėje yra namų darbų įrašai ir ar įrašyti namų darbų duomenys atitinka nustatytus standartus(sveikieji skaičiai nuo 1 iki 10 ir ar nėra įrašyta raidė). Pasitaikius išimčiai išmetama atitinkama klaida.

## Failų aprašymas
* main.cpp – pagrindinis programos failas, kuris inicijuoja ir vykdo pagrindinę programos logiką.
* Stud.cpp – faile įgyvendinti visi metodai, naudojami programoje, susiję su studentų duomenų apdorojimu.
* Files.cpp – faile aprašyti metodai, skirti failų generavimui ir nuskaitymui.
* Grupavimas.cpp – faile pateiktos trys strategijos, skirtos studentų grupavimui.
* MyLib.h – faile deklaruotos visos programoje naudojamos bibliotekos.
* Stud.h – faile aprašyta Stud struktūra, apibrėžianti studentą, ir deklaruotos su ja susijusios funkcijos.
* Timer.h – faile aprašyta klasė, skirta laiko matavimui programos vykdymo metu.
  
**Metodai:**
* Vartotojas gali pasirinkti, ar studentų informaciją nuskaityti iš tekstinio failo, ar įvesti rankiniu būdu.
* Jei vartotojas pasirenka nuskaityti informaciją iš tekstinio failo, suteikiama galimybė sugeneruoti naujus tekstinius failus.
* Įvedant informaciją rankiniu būdu, vartotojas gali sugeneruoti atsitiktinius namų darbų ir egzamino rezultatus.
* Vartotojas gali pasirinkti, kaip skaičiuoti galutinį rezultatą – naudojant namų darbų medianą arba vidurkį.

**Metodai su failų generavimu:**
* Sugeneruojami 5 nauji tekstiniai failai.
* Nauji failai nuskaitomi ir studentai grupuojami pagal galutinį pažymį: jei galutinis pažymys yra nemažesnis už 5, studentas priskiriamas „smart“ grupei, kitaip – „dumb“ grupei.
* Naudotojui leidžiama pasirinkti, pagal kokius kriterijus išrūšiuoti studentus, įrašant juos į rezultatų failus, taip pat pasirinkti, pagal kurią strategiją juos grupuoti.
<a/>

## Programos įdiegimo instrukcija
Nukopijuokite projekto direktoriją, sukuriame buid direktoriją ir į ją persikeliame:
   ```
   cd projekto_direktorija
   mkdir build
   cd build
   ```
Paleidžiame CMake, kad sugeneruotų reikalingus failus:
   ```
   cmake ..
   ```
Sukompiliuojame kodą, sukuriame .exe failą:
   
   ```
   cmake --build . --config Release
   ```
Lengvesniam paleidimui unzipinus projektą paleiskite **run.bat** failą.  

----------------------
## Testavimas
V0.2, v0.3 ir v1.0 dalyse buvo atliktas testavimas, naudojant sugeneruotus 5 failus. Testavimas buvo atliktas **6** kartus, o gauti programos vykdymo laikai buvo panaudoti vidurkiui apskaičiuoti. Buvo naudojami dviejų tipų konteineriai: ```std::vector``` ir ```std::list```. Žemiau pateikiamos v0.2, v0.3 ir v1.0 dalių testavimo rezultatų suvestinės.

**Kompiuterio su kuriuo buvo atliekami testai specifikacijos:**
* CPU: Intel(R) Core(TM) Ultra 7 155H **3.80 GHz**
* RAM: 16 GB
* SDD: 1 TB

# V1.1
**v1.1 atnaujinimai:** Programam nuo šiol naudoja class tipo realizacija, vietoje struct. \

**Testavimui naudojamos didesnės apimties failai, norint išsiaiškinti kaip pokytis iš struct į class tipą paveikė didesnės apimties failų veikimo spartą.**
Naudojama 3 grupavimo strategija ir lists.

### Failas: Studentai 1000000
| VEIKSMAS | VYKDYMO VID.(struct - lst) | VYKDYMO VID.(class - lst) |
| --- | --- | --- |
| Failo nuskaitymas                 | 6.109984 s| 7.88116 s|
| Failo rušiavimas                  | 0.2250646 s| 0.32491 s|
| Failo grupavimas                  | 0.08983824 s| 0.10684 s|
| Studentų išvedimas į smart failą  | 0.6137734 s| 0.76192 s|
| Studentų išvedimas į dumb failą   | 0.422014 s| 0.55333 s|

----------------------

### Failas: Studentai 10000000

| VEIKSMAS | VYKDYMO VID.(struct - lst) | VYKDYMO VID.(class - lst) |
| --- | --- | --- |
| Failo nuskaitymas                  | 57.26326 s| 77.97883 s|
| Failo rušiavimas                   | 2.928294 s| 4.32859 s|
| Failo grupavimas                    | 0.8334702 s| 1.20533 s|
| Studentų išvedimas į smart failą   | 5.74896 s| 7.71917 s|
| Studentų išvedimas į dumb failą    | 3.777118 s| 5.48454 s|

**Testavimo išvados: **
* Naudojant class vietoj struct programos veikimo efektyvumas sumažėja, tačiau tai gali būti dėl to, nes class paprastai turi daugiau funkcionalumo, pavyzdžiui, įtrauktus metodus ir papildomas saugumo savybes, kurios gali padidinti atminties ir procesoriaus naudojimą

## Struct ir Klasės versija ištirta su optimizavimo "flagais" (yra lentelė: greitis, exe failo dydis)
### Class - list
| FLAG | LAIKAS | .exe FAILO DYDIS |
| --- | --- | --- |
| -O1 | 181.3833 s | 163.8496 KB |
| -O2 | 168.82811 s | 163.7412 KB |
| -O3 | 170.6521 s | 168.7304 KB |

### Class - vector
| FLAG | LAIKAS | .exe FAILO DYDIS |
| --- | --- | --- |
| -O1 | 140.3943 s | 185.3867 KB |
| -O2 | 139.7370 s | 180.3212 KB |
| -O3 |  138.5772 s | 218.7763 KB |

### Struct - list
| FLAG | LAIKAS | .exe FAILO DYDIS |
| --- | --- | --- |
| -O1 | 169.1964 s | 162.8779 KB |
| -O2 | 162.7343 s | 161.9873 KB |
| -O3 | 163.4852 s | 165.8007 KB |

### Struct - vector
| FLAG | LAIKAS | .exe FAILO DYDIS |
| --- | --- | --- |
| -O1 | 137.7089 s | 191.4091 KB |
| -O2 | 125.9297 s | 185.9580 KB |
| -O3 | 125.8531 s | 203.1005 KB |

 **Eksperimento tyrimo išvados:**
*  Naudojant vektorių, vykdomojo failo dydis buvo žymiai didesnis (iki 203 KB), o mažiausias dydis užfiksuotas struktūros su list atveju (~161 KB).
* -O2 optimizacija pasiūlė geriausią balansą tarp vykdymo laiko ir failo dydžio; -O3 dažnai pagerindavo tik laiką, bet padidindavo failo dydį.
* Struktūra buvo efektyvesnė pagal laiką visais atvejais, tačiau klasės su vektoriumi našumas buvo panašus į struktūrą su vektoriumi.

Rekomendacijos: Struktūros su vektoriumi kombinacija ir -O2 optimizacija yra tinkamiausia, jei svarbus greitis, o struktūra su sąrašu – jei prioritetas mažas failo dydis.

----------------------
  
# V1.0
**v1.0 atnaujinimas:** Vartotojui suteikta galimybė pasirinkti, kokią strategiją jis/ji nori naudoti atliekant studentų grupavimą. 
* 1 strategija - skaidymas į du naujus to paties tipo konteinerius: "dumb" ir "smart".
* 2 strategija - skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "smart".
* 3 startefija - 2 strategijos patobulinimas naudojant funkcija partition.
  
### Failas: Studentai 1000
| VEIKSMAS | VYKDYMO VID.(vector-2str) | VYKDYMO VID.(list-2str) | VYKDYMO VID.(vector-3str) | VYKDYMO VID.(list-3str) |
| --- | --- | --- |--- | --- |
| Failo nuskaitymas                  | 0.01044758 s | 0.019020 s| 0.0102307 s | 0.020861 s|
| Failo rušiavimas                   | 0.0003314 s | 0.000228 s| 0.0002818 s | 0.0000924 s|
| Failo grupavimas                   | 0.00020226 s | 0.000085 s| 0.0000639 s | 0.000096 s|
| Studentų išvedimas į smart failą   | 0.00250062 s | 0.003435 s| 0.0025763 s | 0.002818 s|
| Studentų išvedimas į dumb failą    | 0.00140596 s | 0.016829 s| 0.0014608 s | 0.0013931 s|

----------------------

### Failas: Studentai 10000
| VEIKSMAS | VYKDYMO VID.(vector-2str) | VYKDYMO VID.(list-2str) | VYKDYMO VID.(vector-3str) | VYKDYMO VID.(list-3str) |
| --- | --- | --- |--- | --- |
| Failo nuskaitymas                  | 0.0816417 s | 0.085794 s| 0.0905467 s | 0.092395 s|
| Failo rušiavimas                   | 0.00451634 s| 0.002108 s| 0.0042513 s | 0.0012073 s|
| Failo grupavimas                   | 0.00206306 s| 0.001052 s| 0.0006844 s | 0.0007259 s|
| Studentų išvedimas į smart failą   | 0.0117262 s | 0.011443 s| 0.0109514 s | 0.0107712 s|
| Studentų išvedimas į dumb failą    | 0.00751514 s| 0.009215 s| 0.0070881 s | 0.0078009 s|

----------------------

### Failas: Studentai 100000
| VEIKSMAS | VYKDYMO VID.(vector-2str) | VYKDYMO VID.(list-2str) | VYKDYMO VID.(vector-3str) | VYKDYMO VID.(list-3str) |
| --- | --- | --- |--- | --- |
| Failo nuskaitymas                  | 0.6415938 s | 0.750852 s| 0.7453039 s | 0.6484366 s|
| Failo rušiavimas                   | 0.04712624 s | 0.015056 s| 0.0495826 s | 0.0182077 s|
| Failo grupavimas                   | 0.01539674 s | 0.016468 s| 0.0072107 s | 0.00993212 s|
| Studentų išvedimas į smart failą   | 0.07577556 s| 0.083223 s| 0.0806573 s | 0.08293438 s|
| Studentų išvedimas į dumb failą    | 0.05242182 s | 0.058222 s| 0.0531508 s | 0.05512132 s|

----------------------

### Failas: Studentai 1000000
| VEIKSMAS | VYKDYMO VID.(vector-2str) | VYKDYMO VID.(list-2str) | VYKDYMO VID.(vector-3str) | VYKDYMO VID.(list-3str) |
| --- | --- | --- |--- | --- |
| Failo nuskaitymas                 | 6.098156 s  | 6.669537 s| 7.2731120 s | 6.109984 s|
| Failo rušiavimas                  | 0.4605068  s | 0.121612 s| 0.5361923 s | 0.2250646 s|
| Failo grupavimas                  | 0.09134838 s  | 0.229607 s| 0.0622364 s | 0.08983824 s|
| Studentų išvedimas į smart failą  | 0.5152744  s | 0.616712 s| 0.6443484 s | 0.6137734 s|
| Studentų išvedimas į dumb failą   | 0.3749948  s | 0.458501 s| 0.4263662 s | 0.422014 s|

----------------------

### Failas: Studentai 10000000

| VEIKSMAS | VYKDYMO VID.(vector-2str) | VYKDYMO VID.(list-2str) | VYKDYMO VID.(vector-3str) | VYKDYMO VID.(list-3str) |
| --- | --- | --- |--- | --- |
| Failo nuskaitymas                  | 62.77496 s | 64.72142 s| 72.2938054 s | 57.26326 s|
| Failo rušiavimas                   | 5.333358 s | 3.13935 s| 6.2909252 s | 2.928294 s|
| Failo grupavimas                    | 0.9854816 s| 1.25798 s| 0.5787044 s | 0.8334702 s|
| Studentų išvedimas į smart failą   | 5.417268 s | 6.67649 s| 6.5107646 s | 5.74896 s|
| Studentų išvedimas į dumb failą    | 3.800548 s | 4.57997 s| 4.6918214  s| 3.777118 s|

----------------------

## Testavimo išvados:
Buvo testuojama programa naudojant dvi skirtingas struktūras: ```std::vector``` ir ```std::list```. Programos veikimo laikai buvo lyginami. </br>
**Galima padaryti išvadas:**
* 3 srategija(tiek vector, tiek list) dažniausiai yra spartesnė nei 2 strategija, ypač rūšiavimo ir grupavimo operacijose. Tai rodo, kad 3 strategija efektyviau tvarko duomenis, greičiau atlieka šias operacijas.
* Didėjant duomenų kiekiui, tiek vector, tiek list struktūrose išlieka panaši vykdymo laiko tendencija – 3 strategija yra greitesnė nei 2 strategija. Tai rodo, kad pasirinkus tinkamą formatą, galima sumažinti vykdymo laiką nepriklausomai nuo struktūros tipo.
* List struktūros šiek tiek praranda našumą esant labai dideliems duomenų rinkiniams. Tai leidžia manyti, kad vector struktūros yra labiau skalabilios su didėjančiu duomenų kiekiu.
  
# v0.3
**V0.3 atnaujinimas:** 
* Norint atlikti testavimus ir palyginti dviejų skirtingų rūšių konteinerius, programa buvo pritaikyta ne tik vector tipo konteineriams, bet ir list tipo konteineriams.
* Surenkant studentu duomenis ranka, programa apskaičiuoja ne tik galutinį rezultatą, tačiau ir struktūros adresą kompiuterio atmintyje. <br/>
### Failas: Studentai 1000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0159676167 s | 0.0123800667 s |
| Failo grupavimas  | 0.0019471667 s | 0.0013408 s |
| Failo rušiavimas  | 0.0002987667 s | 0.0004841333 s |
| Studentų išvedimas į smart failą | 0.0030953833 s | 0.0031049833 s |
| Studentų išvedimas į dumb failą | 0.00191965 s | 0.0015635833 s |
<img src="https://github.com/user-attachments/assets/eccc11f9-8d10-4f0f-ba1e-778801e60b96" alt="Description" width="500"/>

----------------------
### Failas: Studentai 10000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0985081333 s | 0.0950360667 s |
| Failo grupavimas  | 0.0076673167 s | 0.0069883833 s |
| Failo rušiavimas  | 0.0052359 s | 0.0018065333 s |
| Studentų išvedimas į smart failą | 0.0130139 s | 0.0126294 s |
| Studentų išvedimas į dumb failą | 0.0099617833 s | 0.0095311167 s |
<img src="https://github.com/user-attachments/assets/63142280-c428-4fac-8e0e-f90954c2518b" alt="Description" width="500"/>

----------------------
### Failas: Studentai 100000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.751953875 s | 0.7402695 s |
| Failo grupavimas  | 0.0603202 s | 0.0593329667 s |
| Failo rušiavimas  | 0.0599166875 s | 0.0301281833 s |
| Studentų išvedimas į smart failą | 0.1135195 s | 0.0991398333 s |
| Studentų išvedimas į dumb failą | 0.0726314667 s | 0.0720664 s |
<img src="https://github.com/user-attachments/assets/0f1a3a84-f97b-48ce-8d63-2e0b298907b8" alt="Description" width="500"/>

----------------------
### Failas: Studentai 1000000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 8.2884075 s | 8.067803333 s |
| Failo grupavimas  | 0.851942625 s | 0.6628698333 s |
| Failo rušiavimas  | 0.71661653 s | 0.3381395 s |
| Studentų išvedimas į smart failą | 1.0000588167 s | 0.822413 s |
| Studentų išvedimas į dumb failą | 0.6644465 s | 0.5990218333 s |
<img src="https://github.com/user-attachments/assets/8262d682-3c40-490e-a7ef-ca1db22052e6" alt="Description" width="500"/>

----------------------
### Failas: Studentai 10000000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 85.1526125 s | 82.4037 s |
| Failo grupavimas  | 5.68810375 s | 5.05564 s | 
| Failo rušiavimas  | 6.61167625 s | 6.0088216667 s | 
| Studentų išvedimas į smart failą | 10.1445716667 s | 9.6545516667 s |
| Studentų išvedimas į dumb failą | 7.6079633333 s | 7.146921 s |
<img src="https://github.com/user-attachments/assets/a41b041b-e72d-440e-ae99-5e3d2833e364" alt="Description" width="500"/>
----------------------

## Testavimo išvados
Buvo testuojama programa naudojant dvi skirtingas struktūras: ```std::vector``` ir ```std::list```. Programos veikimo laikai buvo lyginami. </br>
**Galima padaryti išvadas:**
* Lyginant vector ir list, programa sparčiau veikia, tačiau pokyčiai yra neženklūs. Atsižvelgiant į skaičius, didesnius pokyčius galime pastebėti tik didesniuose duomenų failuose.
* List yra labiau tinkamas naudoti su dideliais duomenų kiekiais, priešingai negu vector, kuris geriau veikia mažesnio duomenų kiekio failuose. 

# v0.2
**V0.2 atnaujinimas:** 
* Vartotojas nuo šiol gali pasirinkti failus ne tik nuskaityti, bet ir sugeneruoti. Naudotojui pasirinkus generavimo metodą, bus sugeneruojami 5 skirtingi failai: studentai 1000, studentai 10000, studentai 100000, studentai 1000000 studentai 10000000
* Studentai pagal galutinį vidurkį buvo sugrupuoti į protingus (galutinis įvertinimas > 5) ir ne tiek protingus studentus (galutinis įvertinimas < 5). Dvi skirtingos grupės yra išvedamos į skirtinguus failus
* Vartotojui suteikiama galimybė pasirinkti kaip rušiuoti studentų failus
* Buvo atliekami testavimai su vektoriu sturktūromis. 
<br/>


### Failas: Studentai 1000

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | 
| --- | --- |
| Failo nuskaitymas | 0.0159676167 s |
| Failo grupavimas  | 0.0019471667 s | 
| Failo rušiavimas  | 0.0002987667 s | 
| Studentų išvedimas į smart failą | 0.0030953833 s |
| Studentų išvedimas į dumb failą | 0.00191965 s | 

----------------------

### Failas: Studentai 10000

| VEIKSMAS | VYKDYMO VIDURKIS(vector) |
| --- | --- | 
| Failo nuskaitymas | 0.0985081333 s | 
| Failo grupavimas  | 0.0076673167 s | 
| Failo rušiavimas  | 0.0052359 s | 
| Studentų išvedimas į smart failą | 0.0130139 s | 
| Studentų išvedimas į dumb failą | 0.0099617833 s | 

----------------------

### Failas: Studentai 100000

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | 
| --- | --- | 
| Failo nuskaitymas | 0.751953875 s | 
| Failo grupavimas  | 0.0603202 s | 
| Failo rušiavimas  | 0.0599166875 s | 
| Studentų išvedimas į smart failą | 0.1135195 s | 
| Studentų išvedimas į dumb failą | 0.0726314667 s | 

----------------------

### Failas: Studentai 1000000

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | 
| --- | --- |
| Failo nuskaitymas | 8.2884075 s |
| Failo grupavimas  | 0.851942625 s |
| Failo rušiavimas  | 0.71661653 s | 
| Studentų išvedimas į smart failą | 1.0000588167 s | 
| Studentų išvedimas į dumb failą | 0.6644465 s |

----------------------

### Failas: Studentai 10000000

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | 
| --- | --- | 
| Failo nuskaitymas | 85.1526125 s |
| Failo grupavimas  | 5.68810375 s |
| Failo rušiavimas  | 6.61167625 s | 
| Studentų išvedimas į smart failą | 10.1445716667 s | 
| Studentų išvedimas į dumb failą | 7.6079633333 s |


