#include <stdio.h>
#include <limits.h>
#pragma warning (disable: 4996)


int main() {
	int c_str, c_stlb, elem,res_i, res_j, f=0;
	scanf("%d%d", &c_str, &c_stlb);
	int max_el_str[c_str];
	int min_el_stlb[c_stlb];
	int index[10];

	for (int i=0;i<c_str;i++){
        max_el_str[i]=INT_MIN;
	}
	for (int i=0;i<c_stlb;i++){
        min_el_stlb[i]=INT_MAX;
	}

	for (int i = 0; i < c_str; i++) {
		for (int j = 0; j < c_stlb; j++) {
			scanf("%d", &elem);
			if (elem<min_el_stlb[j])
                min_el_stlb[j]=elem;
            if (elem > max_el_str[i]){
                max_el_str[i]=elem;
                index[i]=j;
            }
        }
	}

	for (int i = 0; i < c_str; i++) {
        if (min_el_stlb[index[i]] == max_el_str[i]) {
                f=1;
				res_i = i;
				res_j = index[i];
				break;
			}
		}

    if (f) printf("%d %d", res_i, res_j);
    else printf("none");
    return 0;
}
