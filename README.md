# Objektinis-programavimas
## Programos aprašymas <br/>
Programa, kuri leidžia vartotojui suvesti arba nuskaityti duomenis apie studenta(vardą, pavardę, namų darbų rezultatus, egzamino rezultatus). Apskaičiuoja studentų galutinius rezultatus paga formulę: Galutinis = 0.4 x namų darbų rezultatai + 0.6 x egzamino įvertinimas. <br />
*Namų darbų rezultatai - vartotojui leidžiama pasirinkti ar namų darbų rezultatus skaičiuoti su mediana ar gauti jų vidurkį.*<br/>
<br/>

**V0.2 atnaujinimas:** Vartotojas nuo šiol gali pasirinkti failu ne tik nuskaityti, bet ir sugeneruoti. Naudotojui pasirinkus generavimo metodą, bus sugeneruojami 5 skirtingi failai: studentai 1000, studentai 10000, studentai 100000, studentai 1000000 studentai 10000000.
<br/>

**Failų paaiškinimas:**
* main.cpp yra pagrindinis failas
* Stud.cpp faile surašytos visi programoje naudojami metodai
* Files.cpp faile surašyti metodai naudojami failų generavimui ir nuskaitymui
* MyLib.h faile aprašytos visos pogramoje naudojamos bibliotekos
* Stud.h faile aprašyta Stud struktūra, kuri aprašo studentą ir metodų deklaracijos
* Timer.h faile aprašytas laiko skaičiavimo klasė.
<a/>

**Metodai:**
* Vartotojas turi pasirinkimą ar nori studento informacija nuskaityti nuo tekstinio failo ar įrašyti rankiniu būdu
* Įrašinėjant rankiniu būdu, vartotojas turi galimybe sugeneruoti atsitiktinius namų darbų ir egzamino rezultatus
* Vartotojas turi galimyę galutinį rezultatą išspausdinti arba skaičiuojant su namų darbų mediana, arba su namų darbų vidurkiu. 

**Nauji metodai:**
* Sugeneruojami 5 nauji failai
* Nauji 5 failai yra nuskaitomi ir sugrupuojami pagal galutinį pažymį. Jeigu galutinis pažymys yra nemažesnis už 5, tada studentas yra priskiriamas prie smart studentu grupes, kitu atveju studentas priskiriamas prie dumb studentu grupes
* Naudotojui leidžiama pasirinkti pagal kurį aspektą išrušiuoti studentus juos įrašinėjant į rezultatų failus.
<a/>
  
  
**Išsimčių valdymas:**
* Klausimuose, kuriuose reikalaujama vartotojo pasirinkti vieną iš dviejų variantų yra naudojama try and catch norint apsaugoti nuo neteisingų įvedimų ir taip pat sistemos lūžimo, jeigu būtų įvesta raidė
* Norint įvesti namų darbų ar egzamino pažymį vartotojas yra apribojamas sveikaisiais skaičiais nuo 1 iki 10
* Nuskaitant failą yra tikrinama ar failas atsidaro, ar nuskaitytoje eilutėje yra namų darbų įrašai ir ar įrašyti namų darbų duomenys atitinka nustatytus standartus(sveikieji skaičiai nuo 1 iki 10 ir ar nėra įrašyta raidė). Pasitaikius išimčiai išmetama atitinkama klaida.

## Programos testavimas <br/>
Buvo atliekamas testavimas naudojant sugeneruotus 5 failus. Testavimas buvo atliktas **8** kartus ir iš gautų programos veikimo laikų buvo išvestas vidurkis. Žemiau pateikta kiekvieno failo testavimo rezultatai.

**Kompiuterio su kuriuo buvo atliekami testai specifikacijos:**
* CPU: Intel(R) Core(TM) Ultra 7 155H **3.80 GHz**
* RAM: 16 GB
* SDD: 1 TB
  
**Failas: Studentai 1000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0159676167 s | 0.0123800667 s |
| Failo grupavimas  | 0.0019471667 s | 0.0013408 s |
| Failo rušiavimas  | 0.0002987667 s | 0.0004841333 s |
| Studentų išvedimas į smart failą | 0.0030953833 s | 0.0031049833 s |
| Studentų išvedimas į dumb failą | 0.00191965 s | 0.0015635833 s |

**Failas: Studentai 10000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0985081333 s | 0.1000360667 s |
| Failo grupavimas  | 0.0076673167 s | 0.0069883833 s |
| Failo rušiavimas  | 0.0052359 s | 0.0018065333 s |
| Studentų išvedimas į smart failą | 0.0130139 s | 0.0126294 s |
| Studentų išvedimas į dumb failą | 0.0099617833 s | 0.0105311167 s |

**Failas: Studentai 100000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.751953875 s | 0.7902695 s |
| Failo grupavimas  | 0.0603202 s | 0.0793329667 s |
| Failo rušiavimas  | 0.0599166875 s | 0.0301281833 s |
| Studentų išvedimas į smart failą | 0.1135195 s | 0.0991398333 s |
| Studentų išvedimas į dumb failą | 0.0726314667 s | 0.0760664 s |

**Failas: Studentai 1000000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 8.2884075 s | 8.067803333 s |
| Failo grupavimas  | 0.851942625 s | 0.6628698333 s |
| Failo rušiavimas  | 0.71661653 s | 0.3381395 s |
| Studentų išvedimas į smart failą | 1.0000588167 s | 0.822413 s |
| Studentų išvedimas į dumb failą | 0.6644465 s | 0.5990218333 s |

**Failas: Studentai 10000000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 85.1526125 s | 82.4037 s |
| Failo grupavimas  | 5.68810375 s | 5.05564 s | 
| Failo rušiavimas  | 6.61167625 s | 6.0088216667 s | 
| Studentų išvedimas į smart failą | 10.1445716667 s | 9.6545516667 s |
| Studentų išvedimas į dumb failą | 7.6079633333 s | 7.146921 s |
