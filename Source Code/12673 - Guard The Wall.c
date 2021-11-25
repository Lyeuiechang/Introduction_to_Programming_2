#include<stdio.h>
#include<stdlib.h>

typedef struct soldier{
    int l;
    int r;
    int len;
} Soldier;

int main(){
    int t = 0;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int n = 0, q = 0;
        Soldier soldierBuff[6000];
        int sections[6000] = {0};
        int weak1stSoldierIdx = 0;
        int weak2ndSoldierIdx = 0;
        int record1st = 99999;
        int record2nd = 99999;
        int guarded = 0;
        scanf("%d %d", &n, &q);

        for(int j = 0; j < q; j++){
            scanf("%d %d", &(soldierBuff[j].l), &(soldierBuff[j].r));

            soldierBuff[j].len = soldierBuff[j].r - soldierBuff[j].l + 1;
            for(int k = soldierBuff[j].l; k <= soldierBuff[j].r; k++){
                sections[k]++;
            }
        }

        for(int j = 0; j < q; j++){ // Iterate Each Soldier to Find Weakest 1st
            int numberOfOnlyGuard = 0;
            for(int k = soldierBuff[j].l; k <= soldierBuff[j].r; k++){
                if(sections[k] == 1){numberOfOnlyGuard++;}
            }
            if(record1st > numberOfOnlyGuard){
                record1st = numberOfOnlyGuard;
                weak1stSoldierIdx = j;
            }
        }

        // Elimenate Record1st
        for(int k = soldierBuff[weak1stSoldierIdx].l; k <= soldierBuff[weak1stSoldierIdx].r; k++){
            sections[k]--;
        }

        for(int j = 0; j < q; j++){ // Iterate Each Soldier to Find Weakest 2nd
            if(j != weak1stSoldierIdx){
                int numberOfOnlyGuard = 0;
                for(int k = soldierBuff[j].l; k <= soldierBuff[j].r; k++){
                    if(sections[k] == 1){numberOfOnlyGuard++;}
                }
                if(record2nd > numberOfOnlyGuard){
                    record2nd = numberOfOnlyGuard;
                    weak2ndSoldierIdx = j;
                }
            }
        }

        // Elimenate Record2nd
        for(int k = soldierBuff[weak2ndSoldierIdx].l; k <= soldierBuff[weak2ndSoldierIdx].r; k++){
            sections[k]--;
        }

        for(int j = 1; j <= n; j++){
            if(sections[j]){guarded++;}
        }

        printf("%d\n", guarded);
    }

    return 0;
}
