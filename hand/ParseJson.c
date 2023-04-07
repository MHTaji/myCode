/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "jsmn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
typedef enum
{
  noValue,
  Thumb,
  Index,
  Middel,
  Ring,
  Pinky
} HandFinger_Typedef;
typedef enum
{
  STOP,
  OPEN,
  CLOSE
} HandStatuse_Typedef;
typedef struct
{
  HandStatuse_Typedef HandStatuse;
  int Value;
} HandState_Typedef;

const char buffer[300] =
    "{\"Thumb\":{\"Status\":\"STOP\",\"Value\":\"284\"},\"Middele\":{\"Status\":\"OPEN\",\"Value\":\"911\"},\"Index\":{\"Status\":\"CLOSE\",\"Value\":\"12\"},\"Ring\":{\"Status\":\"STOP\",\"Value\":\"25\"},\"Pinky\":{\"Status\":\"CLOSE\",\"Value\":\"56\"}}";

static int jsoneq(const char *json, jsmntok_t *tok, const char *s)
{
  if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
      strncmp(json + tok->start, s, tok->end - tok->start) == 0)
  {
    return 0;
  }
  return -1;
}

int main()
{
  HandState_Typedef HandStruct[5]={0,};
  HandFinger_Typedef HandFinger;
  int i;
  int r;
  jsmn_parser p;
  jsmntok_t t[128]; /* We expect no more than 128 tokens */

  jsmn_init(&p);
  r = jsmn_parse(&p, buffer, strlen(buffer), t,
                 sizeof(t) / sizeof(t[0]));
  if (r < 0)
  {
    printf("Failed to parse JSON: %d\n", r);
    return 1;
  }

  /* Assume the top-level element is an object */
  if (r < 1 || t[0].type != JSMN_OBJECT)
  {
    printf("Object expected\n");
    return 1;
  }

  /* Loop over all keys of the root object */
  for (i = 1; i < r; i++)
  {

    if (jsoneq(buffer, &t[i], "Thumb") == 0)
    {
      HandFinger = Thumb;
      /* We may use strndup() to fetch string value */
      // printf("- Thumb: %.*s\n", t[i + 1].end - t[i + 1].start,
      //        buffer + t[i + 1].start);
      i++;
    }
    else if (jsoneq(buffer, &t[i], "Middele") == 0)
    {
      HandFinger = Middel;
      /* We may want to do strtol() here to get numeric value */
      // printf("- Middele: %.*s\n", t[i + 1].end - t[i + 1].start,
      //        buffer + t[i + 1].start);
      i++;
    }
    else if (jsoneq(buffer, &t[i], "Index") == 0)
    {
      HandFinger = Index;
      /* We may want to do strtol() here to get numeric value */
      // printf("- Index: %.*s\n", t[i + 1].end - t[i + 1].start,
      //        buffer + t[i + 1].start);
      i++;
    }
    else if (jsoneq(buffer, &t[i], "Ring") == 0)
    {
      HandFinger = Ring;
      /* We may want to do strtol() here to get numeric value */
      // printf("- Ring: %.*s\n", t[i + 1].end - t[i + 1].start,
      //        buffer + t[i + 1].start);
      i++;
    }
    else if (jsoneq(buffer, &t[i], "Pinky") == 0)
    {
      HandFinger = Pinky;
      /* We may want to do strtol() here to get numeric value */
      // printf("- Pinky: %.*s\n", t[i + 1].end - t[i + 1].start,
      //        buffer + t[i + 1].start);
      i++;
    }
    else if (jsoneq(buffer, &t[i], "Status") == 0)
    {
      char FingerStateBuffer[100] = {
          0,
      };
      /* We may additionally check if the value is either "true" or "false" */
      
      strncpy(FingerStateBuffer, buffer + t[i + 1].start, t[i + 1].end - t[i + 1].start);
      i++;
      // printf("finger state is : %s\n", FingerStateBuffer);
      if (!strncmp("STOP", FingerStateBuffer, 4))
      {
        HandStruct[HandFinger - 1].HandStatuse = STOP;
        // printf("-------------|STOP|--------------\n");
      }
      if (!strncmp(FingerStateBuffer, "OPEN", 4))
      {
        HandStruct[HandFinger - 1].HandStatuse = OPEN;
        // printf("-------------|OPEN|--------------\n");
      }
      if (!strncmp(FingerStateBuffer, "CLOSE", 5))
      {
        HandStruct[HandFinger - 1].HandStatuse = CLOSE;
        // printf("-------------|CLOSE|--------------\n");
      }
    }
    else if (jsoneq(buffer, &t[i], "Value") == 0)
    {
      char FingerValue[100] = {
          0,
      };
      /* We may want to do strtol() here to get numeric value */
      strncpy(FingerValue, buffer + t[i + 1].start, t[i + 1].end - t[i + 1].start);
      i++;
      for (int counter = 0; counter < strlen(FingerValue); counter++)
      {
        // printf("char : %s\n",&FingerValue[counter]);
        if ('0'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 0 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/0");
        }else
        if ('1'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 1 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/1");
        }else
        if ('2'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 2 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/2");
        }else
        if ('3'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 3 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/3");
        }else
        if ('4'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 4 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/4");
        }else
        if ('5'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 5 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/5");
        }else
        if ('6'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 6 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/6");
        }else
        if ('7'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 7 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/7");
        }else
        if ('8'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 8 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/8");
        }else
        if ('9'==FingerValue[counter])
        {
          HandStruct[HandFinger - 1].Value += 9 * pow(10,(strlen(FingerValue) - (counter+1)));
          // printf("finger Value struct is : %d\n", HandStruct[HandFinger - 1].Value);
          // printf("/9");
        }
      }
    }
    else
    {
      printf("Unexpected key: %.*s\n", t[i].end - t[i].start,
             buffer + t[i].start);
    }
  }
  for(int counter=0;counter<5;counter++)
      {
        printf("--------finger number : %d---------\n",counter);
        switch (HandStruct[counter].HandStatuse)
        {
        case CLOSE:
          printf("finger status : CLOSE\n");
          break;
        case STOP:
          printf("finger status : STOP\n");
          break;
        case OPEN:
          printf("finger status : OPEN\n");
          break;
        default:
          break;
        }
        if(HandStruct[counter].Value/100)
        {
          HandStruct[counter].Value++;
        }
        printf("finger value : %d\n",HandStruct[counter].Value);
      }
  return EXIT_SUCCESS;
}