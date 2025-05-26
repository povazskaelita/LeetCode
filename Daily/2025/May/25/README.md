# Zadanie

You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".

 

Constraints:

    1 <= words.length <= 10^5
    words[i].length == 2
    words[i] consists of lowercase English letters.


# Riesenie

Najprv nad tym popremyslajte sami, potom si precitajte riesenie

Vieme, ze palindrom je string, ktory ked otocime je rovnaky. Napriklad "radar". V tomto zadani mame vector stringov, z ktorych potrebujeme zistit dlzku najdlhsie mozneho palindromu, ktory z tychto stringov vieme poskladat. Vieme, ze tieto stringy su vzdy 2-znakove. Co teda vieme o palindrome? Hodilo by sa nam dat si vsetky tieto stringy do hash mapy, cize unordered_map. Mali by sme tam pocetnost stringov ak by sa opakovali, a taktiez by sme ich vedeli vyhladat. Teraz nastavaju dva pripady, ktore mozeme rozobrat. Palindrom moze byt poskladany bud z parov stringu a k nemu reverznemu stringu, alebo z rovnakych stringov, napr. "aa" a "aa". Ak mame nejaky string, mame jeho pocetnost a string k nemu reverzny a jeho pocetnost (vdaka hash mape). Vyberieme z nich minimalnu pocetnost a to priratame k celkovej dlzke ktoru si nazvime length. Ak je reverzny string rovny terajsiemu stringu, tak ma oba znaky rovnake. V takomto pripade: Ak je pocetnost parna, tak mozeme pocetnost jednoducho pripocitat k length. Ak je neparna, tak pripocitame k length pocetnost - 1 (pouzijeme najblizsiu nizsiu parnu pocetnost). Musime si ale uvedomit, ze jeden krat moze byt pocetnost neparna, ale iba jeden krat! Takze ak boli nejake neparne pocetnosti zaznamenane, na konci pred returnom k length pripocitame 1. (To preto, lebo jeden moze byt stredom, a 2 moze mat napr. okolo seba, ako "aa", "aa", "aa"; dalsie mozu byt uz iba parne, lebo stred je uz obsadena, a neparnost by znicila symetriu, cize by to nebol palindrom) Kod si mozte pozriet v [riesenie.cpp](riesenie.cpp).
