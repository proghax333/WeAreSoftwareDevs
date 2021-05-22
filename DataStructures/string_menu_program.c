#include<stdio.h>
#include<stdlib.h>

int size;

int main(int argc, char *argv[])
{
  int  Menu();
  int  Allocate_string(char **, int);
  void Read_string(char *);
  void Show_string(char *);
  void display(int [], int [], int);  
  void string_length(char *, int *);
  void string_copy(char *, char *);
  void string_reverse(char *);
  void string_palindrome(char *, char *, int *);
  void string_word_reverse(char *, char *);
  void count_vows_cons(char *, int *, int *);
  void string_concatenate(char *, char *, char *);
  void string_remove_space(char *);
  void LTrim(char *, int *);
  void RTrim(char *, int *);
  void string_swap(char *, char *, char *);
  void string_compare(char *, char *, int *);
  void lower_to_upper(char *);
  void upper_to_lower(char *);
  void occurence_of_letters(char *, int [], int [], int);
  
  char *str1, *str2, *str3;
  int SL[50], CL[50], NE;
  int i, r, ch, len, check, vows, cons;

  str1 = argv[1];
  
  printf("Enter the max size : ");
  scanf("%d", &size); 

  getchar();
  
  if(str1 == NULL)
  {
    r = Allocate_string(&str1, size);
    if(r == 0)
    {
      return 1;
    }
    printf("\nEnter the string : ");
    Read_string(str1);
  }
  
  r = Allocate_string(&str2, size);
  if(r == 0)
  {
    return 1;
  }
  
  r = Allocate_string(&str3, size);
  if(r == 0)
  {
    return 1;
  }

  while(1)
  {
    system("clear");

    ch = Menu();
    
    switch(ch)
    {
      case 1 : 
         string_length(str1, &len);
         printf("The length of the string '%s' is %d\n", str1, len);
         break;
         
      case 2 : 
         string_copy(str1, str2);
         printf("The copied string is :\n");
         Show_string(str2);
         break;
         
      case 3 : 
         string_reverse(str1);
         printf("The reversed string is :\n");
         Show_string(str1);
         string_reverse(str1);
         break;
         
      case 4 : 
         string_palindrome(str1, str2, &check);
         if(check == 1)
         {
           printf("The string '%s' is palindrome", str1);
         }
         else
         {
           printf("The string '%s' is not palindrome", str1);
         }
         break;
         
      case 5 : 
         string_word_reverse(str1, str2);
         printf("The string after reversing the words of string '%s' is :\n", str1);
         Show_string(str2);
         break;
         
      case 6 : 
         count_vows_cons(str1, &vows, &cons);
         printf("%d vowels and %d consonants are present in the string \n", vows, cons);
         Show_string(str1);
         break;
         
      case 7 : 
         printf("Enter the second string below : ");
         getchar();
         Read_string(str2);
         string_concatenate(str1, str2, str3);
         printf("\nThe string after concatenating '%s' and '%s' is :\n", str1, str2);
         Show_string(str3);
         break;
         
      case 8 : 
         printf("The string before removing white spaces is '%s'\n", str1);
         string_remove_space(str1);
         printf("The string after removing all white spaces is :\n");
         Show_string(str1);
         break;
         
      case 9 :
         printf("The string before LTrim is '%s'\n", str1);
         string_length(str1, &len);
         printf("The length of the string is %d\n", len);
         LTrim(str1, &check);
         if(check == 1)
         {
           printf("No leading space is present\n");
         }
         else
         {
           printf("The string after LTrim is :\n");
           Show_string(str1);
           string_length(str1, &len);
           printf("\nThe length of the string after LTrim is %d", len);
         }
         break;
         
      case 10 :
         printf("Actual string before RTrim is '%s'\n", str1);
         string_length(str1, &len);
         printf("The length of the string is %d\n", len);
         RTrim(str1, &check);
         if(check == 1)
         {
           printf("No trailing space is present\n");
         }
         else
         {
           printf("The string after RTrim is : \n");
           Show_string(str1);
           string_length(str1, &len);
           printf("\nThe length of the string after LTrim is %d", len);
         }
         break;
         
      case 11 : 
         printf("Enter the second string below : \n");
         getchar();
         Read_string(str2);
         string_swap(str1, str2, str3);
         printf("The active string after swapping is :\n");
         Show_string(str1);
         break;

      case 12 : 
         printf("Enter the second string below : ");
         getchar();
         Read_string(str2);
         string_compare(str1, str2, &check);
         if(check == 1)
         {
           printf("The strings '%s' and '%s' are same\n", str1, str2);
         }
         else
         {
           printf("The strings '%s' and '%s' are not same\n", str1, str2);
         }
         break;
         
      case 13 : 
         lower_to_upper(str1);
         printf("The string after converting into upper case is :\n");
         Show_string(str1);         
         break;
         
      case 14 : 
         upper_to_lower(str1);
         printf("The string after converting into lower case is :\n");
         Show_string(str1);         
         break;
         
      case 15 : 
         printf("Enter the number of elements in both arrays : ");
         scanf("%d", &NE);
         occurence_of_letters(str1, SL, CL, NE);
         printf("\nThe frequency of all the letters present in the string '%s' is :\n\n", str1);
         display(SL, CL, NE);
         break;
         
      case 16 : 
         Show_string(str1);
         break;
         
      case 17 :
         printf("EXITING from program\n");
         return 1; 
         break;

      default :
         printf("Enter the correct choice\n");
    }
    getchar();
    getchar();
  }
  return 1;
}

void display(int SL[50], int CL[50], int NE)
{
  int i;
  
  i = 0;
  while(i < NE)
  {
    if(SL[i] != 0)
    {
      printf("%c  :  %d\n", (i + 97), SL[i]);
    }
    i += 1;
  }
  printf("\n");
  i = 0;
  while(i < NE)
  {
    if(CL[i] != 0)
    {
      printf("%c  :  %d\n", (i + 65), CL[i]);
    }
    i += 1;
  }
  return; 
}

void occurence_of_letters(char *str1, int SL[50], int CL[50], int NE)
{
  int i, j;
  
  i = 0;
  while(i < NE)
  {
    SL[i] = 0;
    CL[i] = 0;
    i += 1;
  }
  i = 0;
  while(str1[i] != '\0')
  {
    if((str1[i] >= 97) && (str1[i] <= 122))
    {
      j = (str1[i] - 97);
      SL[j] += 1;
    }
    else if((str1[i] >= 65) && (str1[i] <= 90))
    {
      j = (str1[i] - 65);
      CL[j] += 1;
    }
    i += 1;
  }
  return;
} 

void RTrim(char *str1, int *check)
{
  void string_length(char *, int *);
  
  int i, len;
  
  string_length(str1, &len);
  
  i = 0;
  if(str1[len-1] != ' ' || str1[i] == '\0')
  {
    (*check) = 1;
    return;
  }
  else
  {
    i = (len - 1);
    while(str1[i] == ' ')
    {
      i -= 1;
    }
    str1[i+1] = '\0';
  }
  return;
}

void LTrim(char *str1, int *check)
{
  int i, j;
  
  i = 0;
  if(str1[i] != ' ' || str1[i] == '\0')
  {
    (*check) = 1;
    return;
  }
  else
  {
    while(str1[i] == ' ')
    {
      i += 1;
    }
  }
  j = 0;
  while(str1[i] != '\0')
  {
    str1[j] = str1[i];
    i += 1;
    j += 1;
  }
  str1[j] = '\0';
  return;
}

void string_word_reverse(char *str1, char *str2)
{
  void string_length(char *, int *);
  
  int len, i, j, U;
  
  string_length(str1, &len);
  
  len -= 1;
  i = 0;
  while(len >= 0)
  {
    j = len;
    while(str1[len] != ' ' && len >= 0)
    {
      len -= 1;
    }
    U = len;
    len += 1;
    while(len <= j)
    {
      str2[i] = str1[len];
      len += 1;
      i += 1;
    }
    str2[i] = ' ';
    if(U == (-1))
    {
      str2[i] = '\0';
      return;
    } 
    else
    {
      i += 1;
      len = (U - 1);
    }
  }
  return;
}

void upper_to_lower(char *str1)
{
  int i;
  
  i = 0;
  while(str1[i] != 0)
  {
    if((str1[i] >= 65) && (str1[i] <= 90))
    {
      str1[i] += 32;
    }
    i += 1;
  }
  return;
}

void lower_to_upper(char *str1)
{
  int i;
  
  i = 0;
  while(str1[i] != 0)
  {
    if((str1[i] >= 97) && (str1[i] <= 122))
    {
      str1[i] -= 32;
    }
    i += 1;
  }
  return;
}

void string_swap(char *str1, char *str2, char *str3)
{
  void string_copy(char *, char *);
  
  string_copy(str1, str3);
  string_copy(str2, str1);
  string_copy(str3, str2);
  
  return;
}

void string_remove_space(char *str1)
{
  void remove_space(char *, int);
  
  int i;
  
  i = 0;
  while(str1[i] != '\0')
  {
    if(str1[i] == ' ')
    {
      remove_space(str1, i);
    }
    else
    {
      i += 1;
    }
  }
  return;
}

void remove_space(char *str1, int i)
{
  while(str1[i] != '\0')
  {
    str1[i] = str1[i+1];
    i += 1;
  }
  return;
}

void string_concatenate(char *str1, char *str2, char *str3)
{
  int i, j;
  
  i = 0;
  while(str1[i] != '\0')
  {
    str3[i] = str1[i];
    i += 1;
  }
  str3[i] = ' ';
  i += 1;
  j = 0;
  while(str2[j] != '\0')
  {
    str3[i] = str2[j];
    i += 1;
    j += 1;
  }
  str3[i] = '\0';
  return;  
}

void count_vows_cons(char *str1, int *vows, int *cons)
{  
  int i;
  
  i = 0;
  (*vows) = 0;
  (*cons) = 0;
  while(str1[i] != '\0')
  {
    if(((str1[i] >= 65) && (str1[i] <= 90)) || ((str1[i] >= 97) && (str1[i] <= 122)))
    {
      if(((str1[i] == 'a') || (str1[i] == 'A')))
      {
        (*vows) += 1;
      }
      else if(((str1[i] == 'e') || (str1[i] == 'E')))
      {
        (*vows) += 1;
      }
      else if(((str1[i] == 'i') || (str1[i] == 'I')))
      {
        (*vows) += 1;
      }
      else if(((str1[i] == 'o') || (str1[i] == 'O')))
      {
        (*vows) += 1;
      }
      else if(((str1[i] == 'u') || (str1[i] == 'U')))
      {
        (*vows) += 1;
      }
      else
      {
        (*cons) += 1;
      }
    }
    i += 1;
  }
  return;
}  

void string_compare(char *str1, char *str2, int *check)
{
  int F, i;
  
  (*check) = 1;
  F = 1;
  i = 0;
  while(F == 1)
  {
    if(str1[i] == '\0')
    {  
      F = 0;
    }
    else if(str2[i] == '\0')
    {
      F = 0;
    }
    else if(str1[i] != str2[i])
    {
      (*check) = 0;
      return;
    }
    else
    {
      i += 1;    
    }
  }
  if(str1[i] != '\0')
  {
    (*check) = 0;
  }
  else if(str2[i] != '\0')
  {
    (*check) = 0;
  }
  return;
}

void string_palindrome(char *str1, char *str2, int *check)
{
  void string_copy(char *, char *);
  void string_reverse(char *);
  void string_compare(char *, char *, int *);
  
  string_copy(str1, str2);
  string_reverse(str2);
  string_compare(str1, str2, check);
  return;
}

void string_reverse(char *str1)
{
  void string_length(char *, int *);
  
  int L, U, T;
  
  string_length(str1, &U);
  U -= 1;
  L = 0;
  while(L < U)
  {
    T = str1[L];
    str1[L] = str1[U];
    str1[U] = T;
    L += 1;
    U -= 1;
  }  
  return;
}
 
void string_copy(char *str1, char *str2)
{
  int i;

  i = 0;
  while(str1[i] != '\0')
  {
    str2[i] = str1[i];
    i += 1;
  }
  str2[i] = '\0';
  return;  
}

void string_length(char *str1, int *len)
{
  (*len) = 0;
  while(str1[(*len)] != '\0')
  {
    (*len) += 1;
  }
  return;
}

int Menu()
{
  int ch;

  printf("\t\t***** M E N U *****\n\n");
  printf("1.string length\t\t\t2.Copy string\n");
  printf("3.Reverse string letters\t4.Check Palindrome string\n");
  printf("5.Reverse string words\t\t6.Count vowels and consonants\n");
  printf("7.string concatenate\t\t8.Remove white spaces\n");
  printf("9.LTrim\t\t\t\t10.RTrim\n");
  printf("11.String swap\t\t\t12.String compare\n");
  printf("13.Lower to upper case\t\t14.Upper to lower case\n");    
  printf("15.Occurence of each letters\t16.Display string\n");
  printf("17.EXIT\n\n");
  
  printf("Enter your choice : ");
  scanf("%d", &ch);
  return ch;
}

int Allocate_string(char **p, int size)
{
  (*p) = (char *)calloc(size, sizeof(char));
  if((*p) == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void Read_string(char *p)
{
  int i;
 
  i = 0;
  while(1)
  {
    p[i] = getchar();
    if(p[i] == '\n')
    {
      break;
    }
    else
    {
      i += 1;
    }
  }
  p[i] = '\0';
  return;
}

void Show_string(char *p)
{
  int i;
 
  i = 0;
  while(p[i] != '\0')
  {
    printf("%c", p[i]);
    i += 1;
  }
  return;
}
