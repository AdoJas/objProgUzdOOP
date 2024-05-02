# ***Klasės*** ***ir*** ***struktūros***

## Kompiuterio komponentai naudoti testavimo metu 

|   Komponentas  |                   Pavadinimas                       |                      
|:--------------:|:---------------------------------------------------:|
|     **CPU**    |            `AMD Ryzen 5 3600 6-core`              |
|     **GPU**    |`G.Skill Trident Z RGB DDR4 16GB (2x8GB) 3200MHz`  |
|     **SSD**    |           `Samsung SSD 970 EVO Plus, 500GB`       |

# Penkių taisyklė
## Penkiu taisykle - metodai, sukurti saugiam ir patogiam objektiniam programavimui: 
> 1. Kopijavimo konstruktorius
> 2. Priskyrimo konstruktorius
> 3. Perkelimo konstruktorius
> 4. Perkelimo priskyrimo konstruktorius
> 5. Destruktorius

## Kopijavimo konstruktorius
### Atsakingas uz kompleksini objekto kopijavima, kai objektas turi tuos pacius duomenis arba kintamuosius.

        studentasV(const studentasV &kita);
## Priskyrimo konstruktorius  
### Atsakingas uz kompleksinio objekto priskyrima. 

        studentasV& studentasV::operator=(const studentasV &kita)     
## Perkelimo konstruktorius
### Atsakingas uz kompleksinio objekto perkelima is vieno objekto i kita.

        studentasV::studentasV(studentasV&& kita) noexcept :
                studentasBase(),
                pazymiai(std::move(kita.pazymiai)),
                egzaminas(kita.egzaminas)
## Perkelimo priskyrimo konstruktorius
### Atsakingas uz kompleksinio objekto perkelima ir priskyrima naujam objektui.

        studentasV& studentasV::operator=(studentasV&& kita) noexcept
## Destruktorius
### Atsakingas uz kompleksinio objekto sunaikinima programai baigus veikti.

        studentasV::~studentasV()
## Ivesties metodo perdengimas
### Jei prie >> nurodome tik objekta, >> nuskaito duomenis i visus objekto turimus kintamuosius
        std::istream &operator>>(std::istream &inputas, studentasV &studentas){
            inputas >> studentas.vardas >> studentas.pavarde >> studentas.egzaminas;
            studentas.pazymiai.clear();
            int pazymys;
            while (inputas >> pazymys) {
                studentas.pazymiai.push_back(pazymys);
            }
            return inputas;
        }
## Isvesties metodo perdengimas
### Jei prie << nurodome tik objekta, << isveda visus objekto turimus kintamuosius
        std::ostream& operator<<(std::ostream& outputas, const studentasV &studentas) {
            outputas << studentas.vardas << " " << studentas.pavarde << " " << studentas.egzaminas << " ";
            for (int pazymys : studentas.pazymiai) {
                outputas << pazymys << " ";
            }
            return outputas;
        }

### 5 testu vidutinis greitis netaikant perdengimo
| Uzduotis                      | 1 tukst. studentu | 10 tukst. studentu | 100 tukst. studentu | 1 mil. studentu | 10 mil. studentu |
|:-----------------------------|:-----------------:|:------------------:|:-------------------:|:---------------:|:----------------:|
| Duomenu nuskaitymas is failo |          0.0026477         |          0.0265865          |            0.252269         |          2.81425       |         26.5251         |
| Studentu vektoriaus rusiavimas|           0.0021881       |          0.0336719           |          0.448841           |           5.96909       |         71.667      |
| Studentu isskirstymas i viena nauja vektoriu |  0.0003975  |          0.0042534           |          0.0427784        |            0.490452        |          4.93333     |

### 5 testu vidutinis greitis taikant perdengima
| Uzduotis                      | 1 tukst. studentu | 10 tukst. studentu | 100 tukst. studentu | 1 mil. studentu | 10 mil. studentu |
|:-----------------------------|:-----------------:|:------------------:|:-------------------:|:---------------:|:----------------:|
| Duomenu nuskaitymas is failo |          0.00778871         |          0.0646578          |            0.642699         |          6.65068       |         65.52         |
| Studentu vektoriaus rusiavimas|           0.00150954       |          0.0149694           |          0.150593           |           1.58109       |         15.6407      |
| Studentu isskirstymas i viena nauja vektoriu |  0.000546334  |          0.0059035           |          0.0629156        |            0.649014        |          6.30503     |

## Isvados 
>1. Perdengus funkcijas pagal *rule of five* programos veikimo greitis pasikeite keliuose aspektuose!
>2. Suletejo duomenu nuskaitymas is failo
>3. Pagreitejo studentu vektoriaus rusiavimas
>4. Suletejo studentu skirstymas i studentai bad vektoriu

# ***Ka daro programa?***
>1. Leidzia dinamiskai arba statiskai ivesti studentu duomenis ir dirbti su jais.
>2. Leidzia ivedus studentu vardus ir pavardes generuoti ju pazymius ir dirbti su jais.
>3. Leidzia automatiskai atsitiktinai generuoti studentu vardus, pavardes ir ju pazymius, dirbti su jais.
>4. Leidzia nuskaityti duomenis is failo ir dirbti su tais duomenimis.
>5. Leidzia generuoti studentu duomenu faila su pazymiais, juos nuskaityti ir dirbti su jais.
>6. 5 funkcija, su pridetu pasirinkimu rusiuoti duomenis i skirtingus konteinerius(Vector, list, deque).


# ***Kaip pasinaudoti kodu? (Windows ir macOS)***
>1. Atsisiuntę ir išsisaugoję projekto failus savo kompiuteryje, atsisiųskite CLion IDE. [https://www.jetbrains.com/clion/download/#section=mac]
>2. Aktyvuokite CLion IDE su savo gautu kodu, kuris jums bus atsiūstas i el. pašto adresą, su kuriuo registravotės į JETBRAINS.
>3. Atlikę šiuos žingsnius, atsidarykite failus per CLion.
>4. Atidarius į failus, paspauskite ant Program.cpp du kartus.
>5. Viršuje iššokęs langelis praneš, kad reikia sukonfiguruoti CMake projektą.
>6. Paspauskite šį mygtuką ir nurodykite CMakeLists.txt failo vietą savo kompiuteryje.
>7. Atlikus šiuos žingsnius, lango viršuje paspauskite "RUN" mygtuką.
>8. Smagaus naudojimo!!!
