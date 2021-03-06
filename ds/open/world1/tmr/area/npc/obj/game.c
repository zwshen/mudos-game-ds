//Edit By Tmr 2000/5/9
// V1.0

#include <ansi.h>
#define INDEX "  0 1 2 3 4 5 6 7 8 9"
inherit ITEM;

int score=0,total=0,max=0;
int game_reset();
int show();
int run_map(int x,int y,int arg);
int set_map();
string replace(int arg);

void create()
{
	set_name("掌上遊戲機",({"hand game","game"}) );
	set("long",@long
夢幻七域第一屆線上遊戲比賽專用機種。
    一台小型的遊戲機，攜帶方便。你可以看到遊戲機上頭有張小
紙條，上頭寫著一些指令：

.		觀看遊戲畫面
gsc		察看你所得的分數
reset		重新開始
input x y	輸入座標
hsc		查看你的最高分數

遊戲玩法：當你點選一個色塊時，其鄰近相同顏色的色塊，會逐一消滅，
          而且會依一次所消滅的個數，而增加分數。
          色塊消滅之後，會向左靠。當一個橫排全消滅完後，會向上靠。
long
);
	set_weight(100);
	set("unit","台");
	set("value",100);
	game_reset();
	setup();
}

mixed *a=allocate(10);
string replace(int i)
{
	string word;
	switch(i)	{
	case 0:	word=    "  ";			break;
	case 1:	word=HIG "■" NOR;		break;
	case 2:	word=HIM "■" NOR;		break;
	case 3:	word=HIB "■" NOR;		break;
	case 4:	word=HIW "■" NOR;		break;
	case 5:	word=HIC "■" NOR;		break;
	case 6:	word=HIR "■" NOR;		break;
	}

	return word;
}

int game_reset()
{
	int i,j;
	for (i=0;i<sizeof(a);i++) {
		a[i]=allocate(10);
		for (j=0;j<sizeof(a[i]);j++) {
			a[i][j]=1+random(6);
		}
	}
}

int show()
{
	int i,j;
	string pp;
	pp=HIW INDEX +"\n"NOR;
	for (i=0;i<sizeof(a);i++) {
		pp +=HIW +(string)i+" "NOR;
		for (j=0;j<sizeof(a[i]);j++) {
			pp +=replace(a[i][j]);
		}
		pp+="\n";
	}
	pp+=HIW INDEX +"\n"NOR;
	tell_object(this_player(),pp+"\n\n目前得分："+score+"\n");
	return 1;
}

int run_map(int x,int y,int c)
{
	if(x < 0 || x > 9 || y < 0 || y > 9 )	return 1;
	if( a[x][y]==c ) {
		a[x][y]=0;
		max+=1;
		total += 1;
		run_map(x+1,y,c);
		run_map(x-1,y,c);
		run_map(x,y+1,c);
		run_map(x,y-1,c);
	}
	else
		return 1;
}

int set_map()
{
	int i,j,x,y,flag;
	mixed *b=allocate(10);
	for(i=0;i<sizeof(b);i++) {
		b[i]=allocate(10);
	}
	x=0;	y=0;
	for(i=0;i<sizeof(a);i++) {
		y=0;
		if(flag==1) x+=1;
		flag=0;
		for(j=0;j < sizeof(a[0]);j++) {
			if(a[i][j] !=0 )	{
				flag=1;
				b[x][y]=a[i][j];
				y+=1;	
			}
		}
	}
	//算分數
	score +=max*max;
	max=0;
	a=b;
	return 1;
}

void init()
{
	add_action("do_look",".");
	add_action("do_reset","reset");
	add_action("do_input","input");
	add_action("high_score","hsc");
}
int high_score()
{
	int sc;
	tell_object(this_player(),HIY"你的遊戲最高分： "+(string)sc+" 。\n"NOR);
	return 1;	

}

int do_reset()
{
	score = 0;
	total = 0;
	max = 0;
	game_reset();
	write("更新遊戲Ok。\n");
	return 1;
}

int do_look()
{
	show();
	return 1;
}

int do_input(string arg)
{
	int x,y,c;
	if(!arg )
		return notify_fail("指令格式：input x y (直座標 橫座標)。\n");
	if(sscanf(arg,"%d %d",x,y)!=2 )
		return notify_fail("指令格式：input x y (直座標 橫座標)。\n");
	if(x < 0 || x > 9 || y < 0 || y > 9)
		return notify_fail("輸入的座標只在0~9之間。\n");
	if(a[x][y]==0 )
		return notify_fail("這個位置並沒有可以點選的色塊。\n");
	c=a[x][y];
	if( (y < 9 && c==a[x][y+1] )
	||  (y > 0 && c==a[x][y-1] )
	||  (x < 9 && c==a[x+1][y] )
	||  (x > 0 && c==a[x-1][y] ) 	) {
		run_map(x,y,c);
		set_map();
		show();
		if(total==100) {
			write("恭喜你完全的消掉所有色塊。(你的分數增加一倍。)\n");		
			score*=2;
		}
	}
	else return notify_fail("你所點選的這格色塊無效。\n");
	return 1;
}
