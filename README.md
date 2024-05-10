# ***Klasės ir struktūros***

## Kompiuterio komponentai naudoti testavimo metu 

|   Komponentas  |                   Pavadinimas                       |                      
|:--------------:|:---------------------------------------------------:|
|     **CPU**    |            `AMD Ryzen 5 3600 6-core`              |
|     **GPU**    |`G.Skill Trident Z RGB DDR4 16GB (2x8GB) 3200MHz`  |
|     **SSD**    |           `Samsung SSD 970 EVO Plus, 500GB`       |

# Projekto dokumentacija
## Doxygen
> Projekto dokumentacija galite perzvelgti naudodami savo IDE arba overleaf.com online Latex compiliatoriu, tereikia ikelti latex failo .zip rinkini.

## Testavimas 
> Testavimas buvo darytas su Googel Test Unit testu testavimo frameworku.
> Linkas i Google Test -> https://github.com/google/googletest/releases
> Buvo testuojamos .setVardas(), .setPavarde(), .getVardas(), .getPavarde() bei vectorPartition() funkcijos
> vectorPartition funkcijoje buvo palikta klaida tam, kad vienas testas suveiktu pilnai, .getVardas() ir t.t., o vectorPartition() ne.

## Pirmasis testas
    TEST(TestStudentas, TestStudentasV) {
      studentasV stud;
      stud.setVardas("Jonas");
      stud.setPavarde("Jonaitis");
      EXPECT_EQ(stud.getVardas(), "Jonas");
      EXPECT_EQ(stud.getPavarde(), "Jonaitis");
    }

### Rezultatai
    [==========] Running 2 tests from 2 test suites.
    [----------] Global test environment set-up.
    [----------] 1 test from TestStudentas
    [ RUN      ] TestStudentas.TestStudentasV
    [       OK ] TestStudentas.TestStudentasV (0 ms)
    [----------] 1 test from TestStudentas (0 ms total)

## Antrasis testas

    TEST(VectorPartitionTest, PartitionVector) {
        vector<studentasV> grupeVector;
        vector<studentasV> grupeBad;
        vector<studentasV> grupeGood;
        vector<int> pazymiaiGood = {10, 10, 10, 10, 10};
        vector<int> pazymiaiBad = {1, 1, 1, 1, 1};
        studentasV goodStudent;
        goodStudent.setPazymiaiVector(pazymiaiGood);
        goodStudent.setVidurkis();
        studentasV badStudent;
        badStudent.setPazymiaiVector(pazymiaiBad);
        badStudent.setVidurkis();
        grupeVector.push_back(goodStudent);
        grupeVector.push_back(badStudent);
    
        vectorPartition("1", grupeVector, grupeGood, grupeBad);
        if (!grupeGood.empty() && !grupeBad.empty()) {
            EXPECT_EQ(grupeGood[0].getVidurkis(), goodStudent.getVidurkis());
            EXPECT_EQ(grupeBad[0].getVidurkis(), badStudent.getVidurkis());
        } else {
            FAIL() << "One of the vectors is empty";
        }
    }

### Rezultatai

    [----------] 1 test from VectorPartitionTest
    [ RUN      ] VectorPartitionTest.PartitionVector
    /Users/adomas/Documents/procedurinisProgramavimas/testavimasUnitTest/main.cpp:35: Failure
    Failed
    One of the vectors is empty
    
    [  FAILED  ] VectorPartitionTest.PartitionVector (0 ms)
    [----------] 1 test from VectorPartitionTest (0 ms total)
    
    [----------] Global test environment tear-down
    [==========] 2 tests from 2 test suites ran. (0 ms total)
    [  PASSED  ] 1 test.
    [  FAILED  ] 1 test, listed below:
    [  FAILED  ] VectorPartitionTest.PartitionVector
    
     1 FAILED TEST
    
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
