# Objektinis-programavimas
**Programos aprašymas:** programa, kuri leidžia vartotojui suvesti arba nuskaityti duomenis apie studenta(vardą, pavardę, namų darbų rezultatus, egzamino rezultatus). Apskaičiuoja studentų galutinius rezultatus paga formulę: Galutinis = 0.4 x namų darbų rezultatai + 0.6 x egzamino įvertinimas. <br />
*Namų darbų rezultatai - vartotojui leidžiama pasirinkti ar namų darbų rezultatus skaičiuoti su mediana ar gauti jų vidurkį.*<br />
<br/>
**Failu paaiškinimas:**
*main.cpp yra pagrindinis failas
*Stud.cpp faile surašytos visi programoje naudojami metodai
*MyLib.h faile aprašytos visos pogramoje naudojamos bibliotekos
*Stud.h faile aprašyta Stud struktūra, kuri aprašo studentą ir metodų deklaracijos. <br />
<br />
**Metodai:**
*Vartotojas turi pasirinkimą ar nori studento informacija nuskaityti nuo tekstinio failo ar įrašyti rankiniu būdu
*Įrašinėjant rankiniu būdu, vartotojas turi galimybe sugeneruoti atsitiktinius namų darbų ir egzamino rezultatus
*Vartotojas turi galimyę galutinį rezultatą išspausdinti arba skaičiuojant su namų darbų mediana, arba su namų darbų vidurkiu
<br \>
**Išsimčių valdymas:**
*Klausimuose, kuriuose reikalaujama vartotojo pasirinkti vieną iš dviejų variantų yra naudojama try and catch norint apsaugoti nuo neteisingų įvedimų ir taip pat sistemos lūžimo, jeigu būtų įvesta raidė.
*Norint įvesti namų darbų ar egzamino pažymį vartotojas yra apribojamas sveikaisiais skaičiais nuo 1 iki 10
*Nuskaitant failą yra tikrinama ar failas atsidaro, ar nuskaitytoje eilutėje yra namų darbų įrašai ir ar įrašyti namų darbų duomenys atitinka nustatytus standartus(sveikieji skaičiai nuo 1 iki 10 ir ar nėra įrašyta raidė). Pasitaikius išimčiai išmetama atitinkama klaida

