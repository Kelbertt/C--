void compara (char* s1, char* s2)
{
int i;
// compara
for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++) {
if (s1[i] < s2[i])
return -1;
else if (s1[i] > s2[i])
return 1;
}
// compara se cadeias têm o mesmo comprimento
if (s1[i]==s2[i])
return 0; // cadeias iguais
else if (s2[i]!= '\0')
return -1; // s1 é menor (menos caracteres)
else
return 1; // s2 é menor (menos caracteres)
}

