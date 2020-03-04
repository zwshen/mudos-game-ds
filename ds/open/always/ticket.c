// Luky @DS 1999.9.2
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("夢幻獎卷",({"lottery ticket","lottery","ticket","price_ticket"}) );
	set("long",@LONG
一張10*20公分的彩卷，上面印了一幅精美圖案。
背面還印了一些對獎辦法:

	本彩卷將定時開獎，並將中獎號碼同步刊登於夢幻日報中， 
	請中獎人至附近獎卷行領取獎項。
LONG
);
        set_weight(1);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","張");   //luky
	}
         set("value", 500);
      set("no_sell", 1);
	setup();
	set("volume",1);
}

string short()
{
	string str;
	if(query("time")) str=sprintf("夢幻彩卷(Lottery ticket) [第%d期]",query("time") );
	else str="夢幻彩卷(Lottery ticket)";
        return str;
}

string long()
{
	string str;
	str=sprintf("%s\n"HIW"這是一張第%d期的彩卷，上面的號碼是: %d\n"NOR,query("long"),query("time"),query("number"));
	return str;
}

int is_ticket()
{
	return 1;
}
