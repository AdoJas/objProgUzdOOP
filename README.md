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

## Pirmasis testas - konstruktorius
    TEST(constructorTest, Constructor) {
    studentasV stud;
    EXPECT_EQ(stud.getVardas(), " ");
    EXPECT_EQ(stud.getPavarde(), " ");
    }

### Rezultatai - konstruktorius
    [----------] 1 test from constructorTest
    [ RUN      ] constructorTest.Constructor
    [       OK ] constructorTest.Constructor (0 ms)
    [----------] 1 test from constructorTest (0 ms total)
    
## Antrasis testas - move konstruktorius
    TEST(moveConstructorTest, MoveConstructor) {
    studentasV stud;
    stud.setVardas("Jonas");
    stud.setPavarde("Jonaitis");
    studentasV stud2 = std::move(stud);
    EXPECT_EQ(stud2.getVardas(), "Jonas");
    EXPECT_EQ(stud2.getPavarde(), "Jonaitis");
    GTEST_EXPECT_FALSE(stud.getVardas() == stud2.getVardas());
    }
    

### Rezultatai
    [----------] 1 test from moveConstructorTest
    [ RUN      ] moveConstructorTest.MoveConstructor
    [       OK ] moveConstructorTest.MoveConstructor (0 ms)
    [----------] 1 test from moveConstructorTest (0 ms total)

## Treciasis testas - kopijavimo konstruktorius
    TEST(copyConstructorTest, CopyConstructor) {
    studentasV stud;
    stud.setVardas("Jonas");
    stud.setPavarde("Jonaitis");
    studentasV stud2 = stud;
    EXPECT_EQ(stud2.getVardas(), "Jonas");
    EXPECT_EQ(stud2.getPavarde(), "Jonaitis");
    EXPECT_EQ(stud.getVardas(), stud2.getVardas());
    }

### Rezultatai - kopijavimo konstruktorius
    [----------] 1 test from copyConstructorTest
    [ RUN      ] copyConstructorTest.CopyConstructor
    [       OK ] copyConstructorTest.CopyConstructor (0 ms)
    [----------] 1 test from copyConstructorTest (0 ms total)

## Ketvirtasis testas - priskyrimo konstruktorius
    TEST(assignmentTest, Assignment) {
    studentasV stud;
    stud.setVardas("Jonas");
    stud.setPavarde("Jonaitis");
    studentasV stud2;
    stud2 = stud;
    EXPECT_EQ(stud2.getVardas(), "Jonas");
    EXPECT_EQ(stud2.getPavarde(), "Jonaitis");
    EXPECT_EQ(stud.getVardas(), stud2.getVardas());
    }

### Rezultatai - priskyrimo konstruktorius
    [----------] 1 test from assignmentTest
    [ RUN      ] assignmentTest.Assignment
    [       OK ] assignmentTest.Assignment (0 ms)
    [----------] 1 test from assignmentTest (0 ms total)
    
## Penktasis testas - perkelimo priskyrimo konstruktorius
    TEST(moveAssignmentTest, MoveAssignment) {
    studentasV stud;
    stud.setVardas("Jonas");
    stud.setPavarde("Jonaitis");
    studentasV stud2;
    stud2 = std::move(stud);
    EXPECT_EQ(stud2.getVardas(), "Jonas");
    EXPECT_EQ(stud2.getPavarde(), "Jonaitis");
    GTEST_EXPECT_FALSE(stud.getVardas() == stud2.getVardas());
    }

### Rezultatai - perkelimo priskyrimo konstruktorius
    [----------] 1 test from moveAssignmentTest
    [ RUN      ] moveAssignmentTest.MoveAssignment
    [       OK ] moveAssignmentTest.MoveAssignment (0 ms)
    [----------] 1 test from moveAssignmentTest (0 ms total) 
    
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
