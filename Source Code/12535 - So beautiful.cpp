#include<iostream>
#include<string>
using namespace std;
int i, j, n, count_vowel, current_vowel, last_word, first_word, first_word_buffer, answer;
string s;
string::iterator s_it;
int lyric[200][5] = {0};
int main(void)
{
    cin >> n;
    answer = 0;
    last_word = 0;
    first_word = 0;
    for(i=0;i<n;i++)
    {
        cin >> s;
        count_vowel = -1;
        current_vowel = 0;
        for(s_it=s.begin();s_it!=s.end();s_it++)
        {
            if(*(s_it) == 'a')
            {
                count_vowel++;
                current_vowel = 0;
            }
            else if(*(s_it) == 'e')
            {
                count_vowel++;
                current_vowel = 1;
            }
            else if(*(s_it) == 'i')
            {
                count_vowel++;
                current_vowel = 2;
            }
            else if(*(s_it) == 'o')
            {
                count_vowel++;
                current_vowel = 3;
            }
            else if(*(s_it) == 'u')
            {
                count_vowel++;
                current_vowel = 4;
            }
        }
        lyric[count_vowel][current_vowel]++;
    }
    for(i=0;i<200;i++)
    {
        first_word_buffer = 0;
        for(j=0;j<5;j++)
        {
            last_word = last_word + (lyric[i][j]/2);
            first_word_buffer = first_word_buffer + (lyric[i][j]%2);
        }
        first_word = first_word + first_word_buffer/2;
    }
    if(last_word > first_word)
    {
        answer = answer + first_word + (last_word - first_word)/2;
    }
    else
    {
        answer = answer + last_word;
    }
    cout << answer << endl;
    return 0;
}
