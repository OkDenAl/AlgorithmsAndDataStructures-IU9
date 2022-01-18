#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SPECNUM 6
#define SSIZE 11
#define ELEM struct elem

ELEM {
        int k, balance;
        char *v;
        ELEM *parent, *left, *right;
};

ELEM* initNode(int k, char *v)
{
        ELEM* node = malloc(sizeof(ELEM));
        node->v = malloc((strlen(v) + 1) * sizeof(char));
        strcpy(node->v, v);
        node->k = k;
        node->balance = 0;
        node->parent = node->left = node->right = NULL;
        return node;
}

ELEM* lookup(ELEM* t, int k)
{
        ELEM *x = t;
        while(x != NULL && x->k != k)
                x = k < x->k ? x->left : x->right;
        return x;
}

ELEM* insert(ELEM *t, int k, char *v)
{
        ELEM *y = initNode(k, v);
        if(t == NULL) {
                t = y;
        } else {
                ELEM* x = t;
                for(;;) {
                        if(k < x->k) {
                                if(x->left == NULL) {
                                        x->left = y, y->parent = x;
                                        break;
                                }
                                x = x->left;
                        } else {
                                if(x->right == NULL) {
                                        x->right = y, y->parent = x;
                                        break;
                                }
                                x = x->right;
                        }
                }
        }
        return y;
}

ELEM* replaceNode(ELEM *t, ELEM *x, ELEM *y)
{
        ELEM* p;
        if(x == t) {
                t = y;
                if(y != NULL) y->parent = NULL;
        } else {
                p = x->parent;
                if(y != NULL) {
                        y->parent = p;
                }
                if(p->left == x) {
                        p->left = y;
                } else {
                        p->right = y;
                }
        }
        return t;
}

ELEM* rotateLeft(ELEM *t, ELEM *x)
{
        ELEM *y = x->right;
        t = replaceNode(t, x, y);
        ELEM *b = y->left;
        if(b != NULL) b->parent = x;
        x->right = b;
        x->parent = y;
        y->left = x;
        x->balance--;
        if(y->balance > 0) x->balance -= y->balance;
        y->balance--;
        if(x->balance < 0) y->balance += x->balance;
        return t;
}

ELEM* rotateRight(ELEM *t, ELEM *x)
{
        ELEM *y = x->left;
        t = replaceNode(t, x, y);
        ELEM *b = y->right;
        if(b != NULL) b->parent = x;
        x->left = b;
        x->parent = y;
        y->right = x;
        x->balance++;
        if(y->balance < 0) x->balance -= y->balance;
        y->balance++;
        if(x->balance > 0) y->balance += x->balance;
        return t;
}

ELEM* insertAVL(ELEM *t, int k, char *v)
{
        ELEM *a = insert(t, k, v);
        for(;;) {
                ELEM *x = a->parent;
                if(x == NULL) break;
                if(a == x->left) {
                        x->balance--;
                        if(!x->balance) break;
                        if(x->balance == -2) {
                                if(a->balance == 1) {
                                        t = rotateLeft(t, a);
                                }
                                t = rotateRight(t, x);
                                break;
                        }
                } else {
                        x->balance++;
                        if(!x->balance) break;
                        if(x->balance == 2) {
                                if(a->balance == -1) {
                                        t = rotateRight(t, a);
                                }
                                t = rotateLeft(t, x);
                                break;
                        }
                }
                a = x;
        }
        return t;
}

void free_tree(ELEM *t)
{
        if(t->left != NULL) free_tree(t->left);
        if(t->right != NULL) free_tree(t->right);
        free(t->v);
        free(t);
}

char isSpec(char* spec, char c)
{
        unsigned int i;
        for(i = 0; i < SPECNUM; i++)
                if(c == spec[i]) return i;
        return -1;
}

char isConst(char c)
{
        return (c >= '0' && c <= '9');
}

char isAlpha(char c)
{
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void lexer()
{
        unsigned int n, i, j, ind_temp, entry;
        scanf("%d", &n);
        ELEM *t = NULL;
        char spec[SPECNUM] = "+-*/()";
        char constFlag = 0, identFlag = 0, lookupFlag = 0, rootFlag = 0, c;
        char *temp = calloc(SSIZE, sizeof(char));
        for(i = 0, ind_temp = 0, entry = 0, n += 2; i < n; i++) {
                if(i == n-1) {
                        c = ' ';
                } else {
                        c = getchar();
                }
                char value = isSpec(spec, c);
                if((constFlag || identFlag) && (c == ' ' || value != -1)) {
                        ind_temp = 0;
                        if(constFlag) {
                                printf("CONST %s\n", temp);
                        } else {
                                if(!entry) {
                                        t = insert(t, entry, temp);
                                        printf("IDENT %d\n", entry++);
                                        rootFlag = 1;
                                } else {
                                        rootFlag = 0;
                                }
                                for(j = 0; j < entry && !rootFlag; j++) {
                                        ELEM* l = lookup(t, j);
                                        if(l != NULL && !strcmp(temp, l->v)) {
                                                printf("IDENT %d\n", l->k);
                                                lookupFlag = 1;
                                                break;
                                        } else {
                                                lookupFlag = 0;
                                        }
                                }
                                if(!rootFlag && !lookupFlag) {
                                        t = insertAVL(t, entry, temp);
                                        printf("IDENT %d\n", entry++);
                                }
                        }
                        memset(temp, 0, SSIZE * sizeof(char));
                }
                if(c == ' ') {
                        constFlag = 0;
                        identFlag = 0;
                        continue;
                }
                if(value != -1) {
                        constFlag = 0;
                        identFlag = 0;
                        printf("SPEC %d\n", value);
                        continue;
                }
                if(isConst(c)) {
                        constFlag = identFlag ? 0 : 1;
                        temp[ind_temp++] = c;
                        continue;
                }
                if(isAlpha(c)) {
                        identFlag = 1;
                        temp[ind_temp++] = c;
                }
        }
        free(temp);
        free_tree(t);
}

int main()
{
        lexer();
        return 0;
}
