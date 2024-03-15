/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Tymur Huselnykov
 * Test wygenerowano automatycznie o 2024-01-21 14:46:33.227053
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("STEAD.TX");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("now.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(292, 1);
                char expected_filecontent[293] = "";
        
                strcat(expected_filecontent, "; all properties\nOf substance and of accident, beheld,\nCompounded, yet one individual light\nThe whole.  And of such bond methinks I saw\nThe universal form: for that whenever\nI do but speak of it, my soul dilates\nBeyond her proper self; and, till I speak,\nOne moment seems a longer lethargy,\nT");
                
        
                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "THIS.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 292, file);
                test_error(size == 292, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 292 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 292);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 292);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3419, 1);
                char expected_filecontent[3420] = "";
        
                strcat(expected_filecontent, "XV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotl");
                
        
                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "ALSO");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3419, file);
                test_error(size == 3419, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3419 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3419);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3419);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2868, 1);
                char expected_filecontent[2869] = "";
        
                strcat(expected_filecontent, "ion found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform m");
                
        
                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "QUITE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2868, file);
                test_error(size == 2868, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2868 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2868);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2868);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2014, 1);
                char expected_filecontent[2015] = "";
        
                strcat(expected_filecontent, "housand miles below.\nWhence I my vision, clearer shall before,\nRecover\'d; and, well nigh astounded, ask\'d\nOf a fourth light, that now with us I saw.\n     And Beatrice:  \"The first diving soul,\nThat ever the first virtue fram\'d, admires\nWithin these rays his Maker.\"  Like the leaf,\nThat bows its lithe top till the blast is blown;\nBy its own virtue rear\'d then stands aloof;\nSo I, the whilst she said, awe-stricken bow\'d.\nThen eagerness to speak embolden\'d me;\nAnd I began: \"O fruit!  that wast alone\nMature, when first engender\'d!  Ancient father!\nThat doubly seest in every wedded bride\nThy daughter by affinity and blood!\nDevoutly as I may, I pray thee hold\nConverse with me: my will thou seest; and I,\nMore speedily to hear thee, tell it not \"\n     It chanceth oft some animal bewrays,\nThrough the sleek cov\'ring of his furry coat.\nThe fondness, that stirs in him and conforms\nHis outside seeming to the cheer within:\nAnd in like guise was Adam\'s spirit mov\'d\nTo joyous mood, that through the covering shone,\nTransparent, when to pleasure me it spake:\n\"No need thy will be told, which I untold\nBetter discern, than thou whatever thing\nThou holdst most certain: for that will I see\nIn Him, who is truth\'s mirror, and Himself\nParhelion unto all things, and naught else\nTo him.  This wouldst thou hear; how long since God\nPlac\'d me high garden, from whose hounds\nShe led me up in this ladder, steep and long;\nWhat space endur\'d my season of delight;\nWhence truly sprang the wrath that banish\'d me;\nAnd what the language, which I spake and fram\'d\nNot that I tasted of the tree, my son,\nWas in itself the cause of that exile,\nBut only my transgressing of the mark\nAssign\'d me.  There, whence at thy lady\'s hest\nThe Mantuan mov\'d him, still was I debarr\'d\nThis council, till the sun had made complete,\nFour thousand and three hundred rounds and twice,\nHis annual journey; and, through every light\nIn his broad pathway, saw I him return,\nThousand save sev\'nty times, the whilst I dwelt\nUpon the earth.  The language I");
                
        
                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "MEANT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2014, file);
                test_error(size == 2014, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2014 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2014);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2014);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3072, 1);
                char expected_filecontent[3073] = "";
        
                strcat(expected_filecontent, "r why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and");
                
        
                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "FIVE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3072, file);
                test_error(size == 3072, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3072 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3072);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3072);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(151, 1);
                char expected_filecontent[152] = "";
        
                strcat(expected_filecontent, "fe\nMarcia, with Julia and Cornelia there;\nAnd sole apart retir\'d, the Soldan fierce.\n     Then when a little more I rais\'d my brow,\nI spied the master ");
                
        
                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "CHARGEGE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 151, file);
                test_error(size == 151, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 151 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 151);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 151);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(292, 1);
                char expected_filecontent[293] = "";

                strcat(expected_filecontent, "; all properties\nOf substance and of accident, beheld,\nCompounded, yet one individual light\nThe whole.  And of such bond methinks I saw\nThe universal form: for that whenever\nI do but speak of it, my soul dilates\nBeyond her proper self; and, till I speak,\nOne moment seems a longer lethargy,\nT");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "THIS.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 611, file);
                test_error(size == 292, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 292 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 292);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 292);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3419, 1);
                char expected_filecontent[3420] = "";

                strcat(expected_filecontent, "XV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotl");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ALSO");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3873, file);
                test_error(size == 3419, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3419 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3419);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3419);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2868, 1);
                char expected_filecontent[2869] = "";

                strcat(expected_filecontent, "ion found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform m");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "QUITE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3248, file);
                test_error(size == 2868, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2868 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2868);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2868);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2014, 1);
                char expected_filecontent[2015] = "";

                strcat(expected_filecontent, "housand miles below.\nWhence I my vision, clearer shall before,\nRecover\'d; and, well nigh astounded, ask\'d\nOf a fourth light, that now with us I saw.\n     And Beatrice:  \"The first diving soul,\nThat ever the first virtue fram\'d, admires\nWithin these rays his Maker.\"  Like the leaf,\nThat bows its lithe top till the blast is blown;\nBy its own virtue rear\'d then stands aloof;\nSo I, the whilst she said, awe-stricken bow\'d.\nThen eagerness to speak embolden\'d me;\nAnd I began: \"O fruit!  that wast alone\nMature, when first engender\'d!  Ancient father!\nThat doubly seest in every wedded bride\nThy daughter by affinity and blood!\nDevoutly as I may, I pray thee hold\nConverse with me: my will thou seest; and I,\nMore speedily to hear thee, tell it not \"\n     It chanceth oft some animal bewrays,\nThrough the sleek cov\'ring of his furry coat.\nThe fondness, that stirs in him and conforms\nHis outside seeming to the cheer within:\nAnd in like guise was Adam\'s spirit mov\'d\nTo joyous mood, that through the covering shone,\nTransparent, when to pleasure me it spake:\n\"No need thy will be told, which I untold\nBetter discern, than thou whatever thing\nThou holdst most certain: for that will I see\nIn Him, who is truth\'s mirror, and Himself\nParhelion unto all things, and naught else\nTo him.  This wouldst thou hear; how long since God\nPlac\'d me high garden, from whose hounds\nShe led me up in this ladder, steep and long;\nWhat space endur\'d my season of delight;\nWhence truly sprang the wrath that banish\'d me;\nAnd what the language, which I spake and fram\'d\nNot that I tasted of the tree, my son,\nWas in itself the cause of that exile,\nBut only my transgressing of the mark\nAssign\'d me.  There, whence at thy lady\'s hest\nThe Mantuan mov\'d him, still was I debarr\'d\nThis council, till the sun had made complete,\nFour thousand and three hundred rounds and twice,\nHis annual journey; and, through every light\nIn his broad pathway, saw I him return,\nThousand save sev\'nty times, the whilst I dwelt\nUpon the earth.  The language I");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MEANT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2169, file);
                test_error(size == 2014, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2014 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2014);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2014);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3072, 1);
                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "r why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FIVE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3250, file);
                test_error(size == 3072, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3072 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3072);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3072);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(151, 1);
                char expected_filecontent[152] = "";

                strcat(expected_filecontent, "fe\nMarcia, with Julia and Cornelia there;\nAnd sole apart retir\'d, the Soldan fierce.\n     Then when a little more I rais\'d my brow,\nI spied the master ");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CHARGEGE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 509, file);
                test_error(size == 151, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 151 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 151);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 151);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[293] = "";

                strcat(expected_filecontent, "; all properties\nOf substance and of accident, beheld,\nCompounded, yet one individual light\nThe whole.  And of such bond methinks I saw\nThe universal form: for that whenever\nI do but speak of it, my soul dilates\nBeyond her proper self; and, till I speak,\nOne moment seems a longer lethargy,\nT");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "THIS.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 292; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3420] = "";

                strcat(expected_filecontent, "XV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotl");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ALSO");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3419; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2869] = "";

                strcat(expected_filecontent, "ion found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform m");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "QUITE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2868; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2015] = "";

                strcat(expected_filecontent, "housand miles below.\nWhence I my vision, clearer shall before,\nRecover\'d; and, well nigh astounded, ask\'d\nOf a fourth light, that now with us I saw.\n     And Beatrice:  \"The first diving soul,\nThat ever the first virtue fram\'d, admires\nWithin these rays his Maker.\"  Like the leaf,\nThat bows its lithe top till the blast is blown;\nBy its own virtue rear\'d then stands aloof;\nSo I, the whilst she said, awe-stricken bow\'d.\nThen eagerness to speak embolden\'d me;\nAnd I began: \"O fruit!  that wast alone\nMature, when first engender\'d!  Ancient father!\nThat doubly seest in every wedded bride\nThy daughter by affinity and blood!\nDevoutly as I may, I pray thee hold\nConverse with me: my will thou seest; and I,\nMore speedily to hear thee, tell it not \"\n     It chanceth oft some animal bewrays,\nThrough the sleek cov\'ring of his furry coat.\nThe fondness, that stirs in him and conforms\nHis outside seeming to the cheer within:\nAnd in like guise was Adam\'s spirit mov\'d\nTo joyous mood, that through the covering shone,\nTransparent, when to pleasure me it spake:\n\"No need thy will be told, which I untold\nBetter discern, than thou whatever thing\nThou holdst most certain: for that will I see\nIn Him, who is truth\'s mirror, and Himself\nParhelion unto all things, and naught else\nTo him.  This wouldst thou hear; how long since God\nPlac\'d me high garden, from whose hounds\nShe led me up in this ladder, steep and long;\nWhat space endur\'d my season of delight;\nWhence truly sprang the wrath that banish\'d me;\nAnd what the language, which I spake and fram\'d\nNot that I tasted of the tree, my son,\nWas in itself the cause of that exile,\nBut only my transgressing of the mark\nAssign\'d me.  There, whence at thy lady\'s hest\nThe Mantuan mov\'d him, still was I debarr\'d\nThis council, till the sun had made complete,\nFour thousand and three hundred rounds and twice,\nHis annual journey; and, through every light\nIn his broad pathway, saw I him return,\nThousand save sev\'nty times, the whilst I dwelt\nUpon the earth.  The language I");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MEANT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2014; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "r why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FIVE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[152] = "";

                strcat(expected_filecontent, "fe\nMarcia, with Julia and Cornelia there;\nAnd sole apart retir\'d, the Soldan fierce.\n     Then when a little more I rais\'d my brow,\nI spied the master ");

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CHARGEGE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 151; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(3072, 1);
            char expected_filecontent[3073] = "";

            strcat(expected_filecontent, "r why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and");

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "FIVE");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 341; ++i)
            {
                int res = file_read(filecontent + 9 * i, 9, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 9 * i, 9, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3072);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 3072);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(292, 1);
    char *filecontent1 = (char *)calloc(3419, 1);
    char *filecontent2 = (char *)calloc(2868, 1);
    char *filecontent3 = (char *)calloc(2014, 1);
    char *filecontent4 = (char *)calloc(3072, 1);
    char *filecontent5 = (char *)calloc(151, 1);

            char expected_filecontent0[293] = "";
    char expected_filecontent1[3420] = "";
    char expected_filecontent2[2869] = "";
    char expected_filecontent3[2015] = "";
    char expected_filecontent4[3073] = "";
    char expected_filecontent5[152] = "";

            strcat(expected_filecontent0, "; all properties\nOf substance and of accident, beheld,\nCompounded, yet one individual light\nThe whole.  And of such bond methinks I saw\nThe universal form: for that whenever\nI do but speak of it, my soul dilates\nBeyond her proper self; and, till I speak,\nOne moment seems a longer lethargy,\nT");strcat(expected_filecontent1, "XV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotl");strcat(expected_filecontent2, "ion found no room for other wish.\nWhile the everlasting pleasure, that did full\nOn Beatrice shine, with second view\nFrom her fair countenance my gladden\'d soul\nContented; vanquishing me with a beam\nOf her soft smile, she spake:  \"Turn thee, and list.\nThese eyes are not thy only Paradise.\"\n     As here we sometimes in the looks may see\nTh\' affection mark\'d, when that its sway hath ta\'en\nThe spirit wholly; thus the hallow\'d light,\nTo whom I turn\'d, flashing, bewray\'d its will\nTo talk yet further with me, and began:\n\"On this fifth lodgment of the tree, whose life\nIs from its top, whose fruit is ever fair\nAnd leaf unwith\'ring, blessed spirits abide,\nThat were below, ere they arriv\'d in heav\'n,\nSo mighty in renown, as every muse\nMight grace her triumph with them.  On the horns\nLook therefore of the cross:  he, whom I name,\nShall there enact, as doth 1n summer cloud\nIts nimble fire.\"  Along the cross I saw,\nAt the repeated name of Joshua,\nA splendour gliding; nor, the word was said,\nEre it was done:  then, at the naming saw\nOf the great Maccabee, another move\nWith whirling speed; and gladness was the scourge\nUnto that top.  The next for Charlemagne\nAnd for the peer Orlando, two my gaze\nPursued, intently, as the eye pursues\nA falcon flying.  Last, along the cross,\nWilliam, and Renard, and Duke Godfrey drew\nMy ken, and Robert Guiscard.  And the soul,\nWho spake with me among the other lights\nDid move away, and mix; and with the choir\nOf heav\'nly songsters prov\'d his tuneful skill.\n     To Beatrice on my right l bent,\nLooking for intimation or by word\nOr act, what next behoov\'d;  and did descry\nSuch mere effulgence in her eyes, such joy,\nIt past all former wont.  And, as by sense\nOf new delight, the man, who perseveres\nIn good deeds doth perceive from day to day\nHis virtue growing; I e\'en thus perceiv\'d\nOf my ascent, together with the heav\'n\nThe circuit widen\'d, noting the increase\nOf beauty in that wonder.  Like the change\nIn a brief moment on some maiden\'s cheek,\nWhich from its fairness doth discharge the weight\nOf pudency, that stain\'d it; such in her,\nAnd to mine eyes so sudden was the change,\nThrough silvery whiteness of that temperate star,\nWhose sixth orb now enfolded us.  I saw,\nWithin that Jovial cresset, the clear sparks\nOf love, that reign\'d there, fashion to my view\nOur language.  And as birds, from river banks\nArisen, now in round, now lengthen\'d troop,\nArray them in their flight, greeting, as seems,\nTheir new-found pastures; so, within the lights,\nThe saintly creatures flying, sang, and made\nNow D. now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform m");strcat(expected_filecontent3, "housand miles below.\nWhence I my vision, clearer shall before,\nRecover\'d; and, well nigh astounded, ask\'d\nOf a fourth light, that now with us I saw.\n     And Beatrice:  \"The first diving soul,\nThat ever the first virtue fram\'d, admires\nWithin these rays his Maker.\"  Like the leaf,\nThat bows its lithe top till the blast is blown;\nBy its own virtue rear\'d then stands aloof;\nSo I, the whilst she said, awe-stricken bow\'d.\nThen eagerness to speak embolden\'d me;\nAnd I began: \"O fruit!  that wast alone\nMature, when first engender\'d!  Ancient father!\nThat doubly seest in every wedded bride\nThy daughter by affinity and blood!\nDevoutly as I may, I pray thee hold\nConverse with me: my will thou seest; and I,\nMore speedily to hear thee, tell it not \"\n     It chanceth oft some animal bewrays,\nThrough the sleek cov\'ring of his furry coat.\nThe fondness, that stirs in him and conforms\nHis outside seeming to the cheer within:\nAnd in like guise was Adam\'s spirit mov\'d\nTo joyous mood, that through the covering shone,\nTransparent, when to pleasure me it spake:\n\"No need thy will be told, which I untold\nBetter discern, than thou whatever thing\nThou holdst most certain: for that will I see\nIn Him, who is truth\'s mirror, and Himself\nParhelion unto all things, and naught else\nTo him.  This wouldst thou hear; how long since God\nPlac\'d me high garden, from whose hounds\nShe led me up in this ladder, steep and long;\nWhat space endur\'d my season of delight;\nWhence truly sprang the wrath that banish\'d me;\nAnd what the language, which I spake and fram\'d\nNot that I tasted of the tree, my son,\nWas in itself the cause of that exile,\nBut only my transgressing of the mark\nAssign\'d me.  There, whence at thy lady\'s hest\nThe Mantuan mov\'d him, still was I debarr\'d\nThis council, till the sun had made complete,\nFour thousand and three hundred rounds and twice,\nHis annual journey; and, through every light\nIn his broad pathway, saw I him return,\nThousand save sev\'nty times, the whilst I dwelt\nUpon the earth.  The language I");strcat(expected_filecontent4, "r why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and");strcat(expected_filecontent5, "fe\nMarcia, with Julia and Cornelia there;\nAnd sole apart retir\'d, the Soldan fierce.\n     Then when a little more I rais\'d my brow,\nI spied the master ");


            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "THIS.BIN");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "ALSO");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "QUITE.TXT");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "MEANT.BIN");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "FIVE");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "CHARGEGE");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 292, file0);
                test_error(size0 == 292, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 292 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 292);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 292);
            
                size_t size1 = file_read(filecontent1, 1, 3419, file1);
                test_error(size1 == 3419, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3419 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 3419);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 3419);
            
                size_t size2 = file_read(filecontent2, 1, 2868, file2);
                test_error(size2 == 2868, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2868 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 2868);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 2868);
            
                size_t size3 = file_read(filecontent3, 1, 2014, file3);
                test_error(size3 == 2014, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2014 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 2014);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 2014);
            
                size_t size4 = file_read(filecontent4, 1, 3072, file4);
                test_error(size4 == 3072, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3072 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 3072);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 3072);
            
                size_t size5 = file_read(filecontent5, 1, 151, file5);
                test_error(size5 == 151, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 151 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 151);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 151);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(292, 1);
            char expected_filecontent[293] = "";

            strcat(expected_filecontent, "; all properties\nOf substance and of accident, beheld,\nCompounded, yet one individual light\nThe whole.  And of such bond methinks I saw\nThe universal form: for that whenever\nI do but speak of it, my soul dilates\nBeyond her proper self; and, till I speak,\nOne moment seems a longer lethargy,\nT");

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "THIS.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 201, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[201] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[201], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(292, 1);
            char expected_filecontent[293] = "";

            strcat(expected_filecontent, "; all properties\nOf substance and of accident, beheld,\nCompounded, yet one individual light\nThe whole.  And of such bond methinks I saw\nThe universal form: for that whenever\nI do but speak of it, my soul dilates\nBeyond her proper self; and, till I speak,\nOne moment seems a longer lethargy,\nT");

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "THIS.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -226, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[66] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[66], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(3419, 1);
            char expected_filecontent[3420] = "";

            strcat(expected_filecontent, "XV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANTO XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotl");

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "ALSO");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 707, SEEK_SET);
            file_seek(file, 1855, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2562] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2562], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SEVEN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SEVEN) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "CREASE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (CREASE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "TAKE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (TAKE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WHEEL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WHEEL) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "ENTER");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (ENTER) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "HAVE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (HAVE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BED");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BED) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WRONGLAS");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WRONGLAS) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "STEAD.TX");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie STEAD.TX, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "STEAD.TX");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "THIS.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[14] = { "THIS.BIN", "ALSO", "QUITE.TXT", "MEANT.BIN", "FIVE", "CHARGEGE", "SEVEN", "CREASE", "TAKE", "WHEEL", "ENTER", "HAVE", "BED", "WRONGLAS" };
            int found_names[14] = { 0 };

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 14; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 14; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "THIS.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "ALSO");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "QUITE.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "MEANT.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "FIVE");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "CHARGEGE");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("steel_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "speech");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST27, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST28, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST29, // Sprawdzanie poprawności działania funkcji file_open
            UTEST30, // Sprawdzanie poprawności działania funkcji file_open
            UTEST31, // Sprawdzanie poprawności działania funkcji file_open
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_read
            UTEST39, // Sprawdzanie poprawności działania funkcji file_read
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_close
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST44, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST45, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(50); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}