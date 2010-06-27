/* A recursive-descent parser generated by peg 0.1.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 12

void
ellc_parser_add_sym(char *chars);

void
ellc_parser_push();

void
ellc_parser_pop();

#ifndef YY_VARIABLE
#define YY_VARIABLE(T)	static T
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yybegin= yypos, 1)
#endif
#ifndef YY_END
#define YY_END		( yyend= yypos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif

#ifndef YY_PART

typedef void (*yyaction)(char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

YY_VARIABLE(char *   ) yybuf= 0;
YY_VARIABLE(int	     ) yybuflen= 0;
YY_VARIABLE(int	     ) yypos= 0;
YY_VARIABLE(int	     ) yylimit= 0;
YY_VARIABLE(char *   ) yytext= 0;
YY_VARIABLE(int	     ) yytextlen= 0;
YY_VARIABLE(int	     ) yybegin= 0;
YY_VARIABLE(int	     ) yyend= 0;
YY_VARIABLE(int	     ) yytextmax= 0;
YY_VARIABLE(yythunk *) yythunks= 0;
YY_VARIABLE(int	     ) yythunkslen= 0;
YY_VARIABLE(int      ) yythunkpos= 0;
YY_VARIABLE(YYSTYPE  ) yy;
YY_VARIABLE(YYSTYPE *) yyval= 0;
YY_VARIABLE(YYSTYPE *) yyvals= 0;
YY_VARIABLE(int      ) yyvalslen= 0;

YY_LOCAL(int) yyrefill(void)
{
  int yyn;
  while (yybuflen - yypos < 512)
    {
      yybuflen *= 2;
      yybuf= realloc(yybuf, yybuflen);
    }
  YY_INPUT((yybuf + yypos), yyn, (yybuflen - yypos));
  if (!yyn) return 0;
  yylimit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(void)
{
  if (yypos >= yylimit && !yyrefill()) return 0;
  ++yypos;
  return 1;
}

YY_LOCAL(int) yymatchChar(int c)
{
  if (yypos >= yylimit && !yyrefill()) return 0;
  if (yybuf[yypos] == c)
    {
      ++yypos;
      yyprintf((stderr, "  ok   yymatchChar(%c) @ %s\n", c, yybuf+yypos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(%c) @ %s\n", c, yybuf+yypos));
  return 0;
}

YY_LOCAL(int) yymatchString(char *s)
{
  int yysav= yypos;
  while (*s)
    {
      if (yypos >= yylimit && !yyrefill()) return 0;
      if (yybuf[yypos] != *s)
        {
          yypos= yysav;
          return 0;
        }
      ++s;
      ++yypos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(unsigned char *bits)
{
  int c;
  if (yypos >= yylimit && !yyrefill()) return 0;
  c= yybuf[yypos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yypos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yybuf+yypos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yybuf+yypos));
  return 0;
}

YY_LOCAL(void) yyDo(yyaction action, int begin, int end)
{
  while (yythunkpos >= yythunkslen)
    {
      yythunkslen *= 2;
      yythunks= realloc(yythunks, sizeof(yythunk) * yythunkslen);
    }
  yythunks[yythunkpos].begin=  begin;
  yythunks[yythunkpos].end=    end;
  yythunks[yythunkpos].action= action;
  ++yythunkpos;
}

YY_LOCAL(int) yyText(int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yytextlen < (yyleng - 1))
	{
	  yytextlen *= 2;
	  yytext= realloc(yytext, yytextlen);
	}
      memcpy(yytext, yybuf + begin, yyleng);
    }
  yytext[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(void)
{
  int pos;
  for (pos= 0;  pos < yythunkpos;  ++pos)
    {
      yythunk *thunk= &yythunks[pos];
      int yyleng= thunk->end ? yyText(thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yytext));
      thunk->action(yytext, yyleng);
    }
  yythunkpos= 0;
}

YY_LOCAL(void) yyCommit()
{
  if ((yylimit -= yypos))
    {
      memmove(yybuf, yybuf + yypos, yylimit);
    }
  yybegin -= yypos;
  yyend -= yypos;
  yypos= yythunkpos= 0;
}

YY_LOCAL(int) yyAccept(int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone();
      yyCommit();
    }
  return 1;
}

YY_LOCAL(void) yyPush(char *text, int count)	{ yyval += count; }
YY_LOCAL(void) yyPop(char *text, int count)	{ yyval -= count; }
YY_LOCAL(void) yySet(char *text, int count)	{ yyval[count]= yy; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yythunkpos0)

YY_RULE(int) yy_eol(); /* 12 */
YY_RULE(int) yy_spc_char(); /* 11 */
YY_RULE(int) yy_CLOSE(); /* 10 */
YY_RULE(int) yy_OPEN(); /* 9 */
YY_RULE(int) yy_sym_char(); /* 8 */
YY_RULE(int) yy_lst(); /* 7 */
YY_RULE(int) yy_sym(); /* 6 */
YY_RULE(int) yy_expr(); /* 5 */
YY_RULE(int) yy_spc(); /* 4 */
YY_RULE(int) yy_eof(); /* 3 */
YY_RULE(int) yy_exprs(); /* 2 */
YY_RULE(int) yy_unit(); /* 1 */

YY_ACTION(void) yy_1_CLOSE(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_CLOSE\n"));
   ellc_parser_pop(); ;
}
YY_ACTION(void) yy_1_OPEN(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_OPEN\n"));
   ellc_parser_push(); ;
}
YY_ACTION(void) yy_1_sym(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_sym\n"));
   ellc_parser_add_sym(yytext); ;
}

YY_RULE(int) yy_eol()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "eol"));  if (!yymatchClass((unsigned char *)"\000\044\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l1;
  yyprintf((stderr, "  ok   %s @ %s\n", "eol", yybuf+yypos));
  return 1;
  l1:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "eol", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_spc_char()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "spc_char"));
  {  int yypos3= yypos, yythunkpos3= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l4;  goto l3;
  l4:;	  yypos= yypos3; yythunkpos= yythunkpos3;  if (!yy_eol()) goto l2;
  }
  l3:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "spc_char", yybuf+yypos));
  return 1;
  l2:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "spc_char", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_CLOSE()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "CLOSE"));  if (!yymatchChar(')')) goto l5;  yyDo(yy_1_CLOSE, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "CLOSE", yybuf+yypos));
  return 1;
  l5:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "CLOSE", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_OPEN()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "OPEN"));  if (!yymatchChar('(')) goto l6;  yyDo(yy_1_OPEN, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "OPEN", yybuf+yypos));
  return 1;
  l6:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "OPEN", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_sym_char()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "sym_char"));
  {  int yypos8= yypos, yythunkpos8= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\000\000\000\100\000\377\007\376\377\377\007\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l9;  goto l8;
  l9:;	  yypos= yypos8; yythunkpos= yythunkpos8;  if (!yymatchChar('-')) goto l7;
  }
  l8:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "sym_char", yybuf+yypos));
  return 1;
  l7:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "sym_char", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_lst()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "lst"));
  {  int yypos11= yypos, yythunkpos11= yythunkpos;  if (!yy_OPEN()) goto l12;  if (!yy_exprs()) goto l12;  if (!yy_CLOSE()) goto l12;  goto l11;
  l12:;	  yypos= yypos11; yythunkpos= yythunkpos11;  if (!yy_OPEN()) goto l10;
  {  int yypos13= yypos, yythunkpos13= yythunkpos;  if (!yy_spc()) goto l13;  goto l14;
  l13:;	  yypos= yypos13; yythunkpos= yythunkpos13;
  }
  l14:;	  if (!yy_CLOSE()) goto l10;
  }
  l11:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "lst", yybuf+yypos));
  return 1;
  l10:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "lst", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_sym()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "sym"));  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l15;  if (!yy_sym_char()) goto l15;
  l16:;	
  {  int yypos17= yypos, yythunkpos17= yythunkpos;  if (!yy_sym_char()) goto l17;  goto l16;
  l17:;	  yypos= yypos17; yythunkpos= yythunkpos17;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l15;  yyDo(yy_1_sym, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "sym", yybuf+yypos));
  return 1;
  l15:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "sym", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_expr()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "expr"));
  {  int yypos19= yypos, yythunkpos19= yythunkpos;  if (!yy_sym()) goto l20;  goto l19;
  l20:;	  yypos= yypos19; yythunkpos= yythunkpos19;  if (!yy_lst()) goto l18;
  }
  l19:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "expr", yybuf+yypos));
  return 1;
  l18:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "expr", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_spc()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "spc"));  if (!yy_spc_char()) goto l21;
  l22:;	
  {  int yypos23= yypos, yythunkpos23= yythunkpos;  if (!yy_spc_char()) goto l23;  goto l22;
  l23:;	  yypos= yypos23; yythunkpos= yythunkpos23;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "spc", yybuf+yypos));
  return 1;
  l21:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "spc", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_eof()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "eof"));
  {  int yypos25= yypos, yythunkpos25= yythunkpos;  if (!yymatchDot()) goto l25;  goto l24;
  l25:;	  yypos= yypos25; yythunkpos= yythunkpos25;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "eof", yybuf+yypos));
  return 1;
  l24:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "eof", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_exprs()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "exprs"));
  {  int yypos27= yypos, yythunkpos27= yythunkpos;  if (!yy_spc()) goto l27;  goto l28;
  l27:;	  yypos= yypos27; yythunkpos= yythunkpos27;
  }
  l28:;	  if (!yy_expr()) goto l26;
  {  int yypos31= yypos, yythunkpos31= yythunkpos;  if (!yy_spc()) goto l31;  goto l32;
  l31:;	  yypos= yypos31; yythunkpos= yythunkpos31;
  }
  l32:;	
  l29:;	
  {  int yypos30= yypos, yythunkpos30= yythunkpos;  if (!yy_expr()) goto l30;
  {  int yypos33= yypos, yythunkpos33= yythunkpos;  if (!yy_spc()) goto l33;  goto l34;
  l33:;	  yypos= yypos33; yythunkpos= yythunkpos33;
  }
  l34:;	  goto l29;
  l30:;	  yypos= yypos30; yythunkpos= yythunkpos30;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "exprs", yybuf+yypos));
  return 1;
  l26:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "exprs", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_unit()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "unit"));  if (!yy_exprs()) goto l35;  if (!yy_eof()) goto l35;
  yyprintf((stderr, "  ok   %s @ %s\n", "unit", yybuf+yypos));
  return 1;
  l35:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "unit", yybuf+yypos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)();

YY_PARSE(int) YYPARSEFROM(yyrule yystart)
{
  int yyok;
  if (!yybuflen)
    {
      yybuflen= 1024;
      yybuf= malloc(yybuflen);
      yytextlen= 1024;
      yytext= malloc(yytextlen);
      yythunkslen= 32;
      yythunks= malloc(sizeof(yythunk) * yythunkslen);
      yyvalslen= 32;
      yyvals= malloc(sizeof(YYSTYPE) * yyvalslen);
      yybegin= yyend= yypos= yylimit= yythunkpos= 0;
    }
  yybegin= yyend= yypos;
  yythunkpos= 0;
  yyval= yyvals;
  yyok= yystart();
  if (yyok) yyDone();
  yyCommit();
  return yyok;
  (void)yyrefill;
  (void)yymatchDot;
  (void)yymatchChar;
  (void)yymatchString;
  (void)yymatchClass;
  (void)yyDo;
  (void)yyText;
  (void)yyDone;
  (void)yyCommit;
  (void)yyAccept;
  (void)yyPush;
  (void)yyPop;
  (void)yySet;
  (void)yytextmax;
}

YY_PARSE(int) YYPARSE(void)
{
  return YYPARSEFROM(yy_unit);
}

#endif
