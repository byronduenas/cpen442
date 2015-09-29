#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include "qgr.h"

#define TEMP 30
#define STEP 0.2
#define COUNT 10000
using namespace std;

string playfairDecipher(string key, string cipherText);
float playfairCrack(string cipherText, string& bestKey);

int main() {
    string cipherText = "VFHZOKLMYBATENHRLMQYHZMRFBVCAGEQETSLNEPWTOGRTPHZQZQEGNMRFBVCAGEQYBMYHNQYHZUWGRYBETNYRNNGPQGWIPVTESKLATENVUQNXKKTQZLRPGYPBFGNGAETRYHFSNCYQSUFXKYRNFQHYGLDRHRYKLRONEGNTNUQQNXKVGFCFBHMPZGLSMEQBFQSUFXKGANHHCPYRDQNXKCEPXKQXRUVOSMUCLNHGBEQABQHQYNXKTOSXENLYRGAETNEBKYHGSQOBFQYMHXPECQSUFXKGRVTHGBFQSUFXKMYHETNLSMRIEBZYRNFBFNGCLCRBENSFKHYLMETHDEUTFNEQYHXSNXNPZSIQNXKGVZQKSYINFSNRZQNXKHWETKQIRKTYTQHPWOCWCNEQSUFXKETSMLTEXWSNGRNQSUFXKKTIFZHNLXRHNNQPCTOPWYRDBYUNSXNTNHNKSSPQHYAYQGBKYBRQSUFXKTPBRQHGNLVQONRNGOSXVKYXRBNHBQHYSRVVHCLQKNHCMDHEGRYQSUFXKUFFOGSECQSUFXKZGLVBFVGXKGWOWKTTPYWXPDFLMRETNAGPYRDQNXKHPLNBZYBNRLCATHZTOLSGSHWRTCLIRPZHETPHZAGAWBHVTBFQSUFXKGAWDVCAZGPRQRDQNXKNGYBMRSQURLWBFQYERLMTNCUTVFKYHFENSWNCLYRGAKTCYURTUHCBFUEQNETNHGMQNQSUFXKYHBPQHOTGNPWTOYBPWEQPWFKXRVZRVQLRCYGTBNQUYWIBRECGNVGWHVGGVLDTOQSUFXKQSREQHFRCBSGFBNQHEQSUFXKGSQOQHZGZGQHGAETNENRYRXBDRLSWECLMYGWGSFHVCQSUFXKCWEQNHGRKTFYNEENHRLMQYHZLRPGOHTFBFQSUFXKMYHCROAGRQRDQNXKNGKYTUNSXPXPEQUEQNQKNYEDSMYBMYHNZLGNQOWIILGNENECGNETBEVZRYVTSMEQPWFQCLLIBGBFKQETQHYAXRLRSQPNNFZLTETPBRKTKQMRDRZETPETHFKTENZEYKSNNSMLRNYMETHDTVNUYCGNKQKSSWRETFNHGUGVZQKSYINFSNEZGNYHRGYRHYRUCWCUQNXKCLTFNRSNTBLSEMSNOSXRLNBPTBXPEQKTOFSNBFGNSWIZRCXKYWSOGSQOBFWVQYETCLOVQHBABHVTBFDBGWGSHWLRKTIFGTLDRETNWDHNIWLTRZQNXKKTIECLBDRYFHHNCRKONRKTCYTPQYFHZFQYHXTNRTRYKLBNQSUFXKPWCSLQDRXPLRGKVCBFGNFOGSECOSRVXPEQQSUFXKSWIZRCQYHZHNCMCHBDSMHUKTZFQYHZXKYWSOYGKTDRCYZQHFBGGVETCLHWEBQYRGTNXPGUGRVTQHYLEHPZLTAGTNBZQSUFXKCMZHTBLVPGTBLRHFVGQSUFXKTNHSQKYAGSEQNTPZHTKTLZTOQYMHTNEVVZVQQNXKVFEANRTBETETNEBKYHTNVCIWUMQHYTVCISSLBFVEDHWYOSRTCLUHCLEZGNGATNHESMIRQSUFXKXKYWSOVWETCLTPEQQHNGPWCVYKRYQSUFXKHWETCEHFPXKTQIQNXKKTIBVGYRQZAGGSTONGKSYINFSNRZQNXKHPLNHYQZRXLWEMNSREYMPWCVBFBDRYQSUFXKTFKXQHQHLZRZGSYRGOQYHXTPHZLCENOWQSUFXKFOGSECQSUFXKHPCLBHHNQFPGMYDFGNKTZETNQSHNCEGZQKCEGZQKTNVTRGEHQHYZGNYSYQQSUFXKGVZQKSYINFSNEZGNTNCEHFSMETCLXPEQKTQIQNABHNZETNYHTOETYCGNSWIZRCXKYWSOXKFBKTQHKSSWREVTOFSKNFNREXSNBXTVZRQLKQXBYRQSEQQSUFXKZHYRNFBFTNTFBHZRBFNGHNDRCPRBSGFBNQHELUKTQZRNUZTPTOBESNPWLSMHQYATETTYRYRXHNXPORGNWQGUYRFYSBSGFBNQHEQSUFXKHPSLTFBDRYHWFBRNQFPGZIQLRCGOQYAZCPBDSMFOXPEQQSUFXKSWIZRCFOXPEQLSFNYMETNETHQKYLHQZTYTHNZFQYHZTPBRLZBREOSMOSRVIWYBHESDQNXKSWIZRCQSUFXKCLETGAKQENKQXSEWSNOSFVXRWPBPNRGNZIBFETGAOSXVEQOSRVXBWQGOYRNFYHGUGRTPRTBABLYMGPENHPGACLZHBKSMNXLBHNYRRQHDEOSMHTQNNETPEZCLLIVZRYOSRUQNXKSWIZRCKQETQHOTGNPWTOQSUFXKFOGSECCRIRIWRYQSUFXKSWIZRCETRYYMRALQDRYRNFBFNGPWGULSRNBRTKXENHETRDVRHYNQXRTWTPCYNGAWBHQFSKQHYZGNQKNYHEMLYMETHFZDVTCYKBHNGOHNVHRYYRZBLRFCFBTVGRTNPWGULCTOSTHFGSFCNHLSFNETQHLTTBBSQSWSFYNTTBECLGZQQHZGUVSLGRTNWYGMSNYBRNGATETNAGPYBFGNETNTXSRYTKBNNFNHYTZESQIWFKLGLMGOWVKSYINFSNRGIRPZECGNZHNSYRQSUFXKYRNFQHYGDBEQYHGULGSDQNXKKTQIKXNESNRYAGUVSLCSSGFBNQHEGULRSMYINHLCRGRNQVETNEPWQVRNGULSXBXKROETZLPWRGBDRYQSUFXKHWETETHDVSNHHZZVGLIWRGMYHVWVWICUQNXKMRPYQHPQTO";
    string key = "IZDQCWXFMUHTENRPABKVLGYOS";
    string currentKey = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    srand (time(NULL));

    int i = 0;
    double score, maxScore = -99e99;
    while(1){
        i++;
        score = playfairCrack(cipherText,currentKey);

        if(score > maxScore){
            maxScore = score;
            printf("best score so far: %f, on iteration %d\n",score,i);
            cout << "Key: " << currentKey << endl;
            cout << "Plaintext: " << playfairDecipher(currentKey, cipherText) << endl;
        }
    }
    return 0;
}

int firstItemInRow(int row) {
    return row * 5;
}

void exchangeTwoLetters(string& key) {
    int i = rand() % 25;
    int j = rand() % 25;
    swap(key[i], key[j]);
}

void swapTwoRows(string& key, int row1, int row2) {
    for(int i = 0; i < 5; i++){
        swap(key[firstItemInRow(row1) + i], key[firstItemInRow(row2) + i]);
    }
}

void swapTwoRows(string& key) {
    int i = rand() % 5;
    int j = rand() % 5;
    swapTwoRows(key, i, j);
}

void swapTwoCols(string& key, int col1, int col2) {
    for(int i = 0; i < 5; i++){
        swap(key[firstItemInRow(i) + col1], key[firstItemInRow(i) + col2]);
    }
}


void swapTwoCols(string& key) {
    int i = rand() % 5;
    int j = rand() % 5;
    swapTwoCols(key, i, j);
}


void reverseKey(string& key) {
    reverse(key.begin(), key.end());
}

string modifiedKey(string key) {
    int i = rand() % 50;
    string modifiedKey = key;
    switch(i){
        case 0: swapTwoRows(modifiedKey); break;
        case 1: swapTwoCols(modifiedKey); break;
        case 2: reverseKey(key); break;
        case 3: for (int j = 0; j < 2; j++) swapTwoRows(modifiedKey, j, 4 - j);
            break;
        case 4: for (int j = 0; j < 2; j++) swapTwoCols(modifiedKey, j, 4 - j);
            break;
        default:
            exchangeTwoLetters(modifiedKey);
    }
    return modifiedKey;
}

int rowFromIndex(int index) {
    return index / 5;
}

int colFromIndex(int index) {
    return index % 5;
}

extern float qgram[];

// From practicalcryptography.com, a function to check the quadgram score of a given text
// Using pracicalcryptography.com's data
double scoreTextQgram(string text){
    int i;
    char temp[4];
    double score = 0;
    int len = text.size();
    for (i=0;i<len-3;i++){
        temp[0]=text.at(i) -'A';
        temp[1]=text.at(i+1) -'A';
        temp[2]=text.at(i+2) -'A';
        temp[3]=text.at(i+3)-'A';
        // we have to index into the correct part of the array
        score += qgram[17576*temp[0] + 676*temp[1] + 26*temp[2] + temp[3]];
    }
    return score;
}

float playfairCrack(string cipherText, string& bestKey){
    string testKey;
    double probability,score;
    string maxKey = bestKey;
    string plainText = playfairDecipher(maxKey,cipherText);
    double maxScore = scoreTextQgram(plainText);
    double bestScore = maxScore;
    double scoreDifference;
    for(float T = TEMP; T >= 0; T-=STEP){
        for(int count = 0; count < COUNT; count++){
            testKey = modifiedKey(maxKey);
            plainText = playfairDecipher(testKey,cipherText);
            score = scoreTextQgram(plainText);
            scoreDifference = score - maxScore;
            if (scoreDifference >= 0){
                maxScore = score;
                maxKey = testKey;
            } else if(T > 0) {
                probability = exp(scoreDifference/T);
                //We have a chance to overwrite the max score and max key for a given
                //playfairCrack call to prevent stagnating at local maxima
                //The smaller the score difference, the higher chance we overwrite the maxKey (exp(scoreDifference/T))
                //The longer the function goes, the less likely we overwrite the maxKey (T)
                if(probability > 1.0*rand()/RAND_MAX){
                    maxScore = score;
                    maxKey = testKey;
                }
            }
            if(maxScore > bestScore){
                bestScore = maxScore;
                bestKey = maxKey;
            }
        }
    }
    return bestScore;
}

string playfairDecipher(string key, string cipherText){
    string result = "";
    for (int i = 0; i < cipherText.size(); i += 2){
        char firstChar = cipherText[i];
        char secondChar = cipherText[i+1];
        int firstIndex = key.find(firstChar);
        int secondIndex = key.find(secondChar);
        int firstRow = rowFromIndex(firstIndex);
        int secondRow = rowFromIndex(secondIndex);
        int firstCol = colFromIndex(firstIndex);
        int secondCol = colFromIndex(secondIndex);
        if(firstRow == secondRow){
            //Decrypt by choosing left of each letter w/ wrapping around
            if(firstCol == 0){
                result += key.at(firstIndex + 4);
                result += key.at(secondIndex - 1);
            }else if(secondCol == 0){
                result += key.at(firstIndex - 1);
                result += key.at(secondIndex + 4);
            }else{
                result += key.at(firstIndex - 1);
                result += key.at(secondIndex - 1);
            }
        }else if(firstCol == secondCol){
            //Decrypt by choosing letter above of each letter w/ wrapping around
            if(firstRow == 0){
                result += key.at(firstIndex + 20);
                result += key.at(secondIndex - 5);
            }else if(secondRow == 0){
                result += key.at(firstIndex - 5);
                result += key.at(secondIndex + 20);
            }else{
                result += key.at(firstIndex - 5);
                result += key.at(secondIndex - 5);
            }
        }else{
            result += key.at(5*firstRow + secondCol);
            result += key.at(5*secondRow + firstCol);
        }
    }
    return result;
}