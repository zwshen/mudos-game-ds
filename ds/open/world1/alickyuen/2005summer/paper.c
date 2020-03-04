/*
  Name: /open/always/paper.c
  Copyright: DS
  Author: Alickyuen & Whoami
  Date: 06/09/05 11:36
  Description: Gift for 2005 Summer Game
*/


#include <ansi2.h>
#include <armor.h>

inherit EQUIP;

void setup();

void create()
{
	set_name( HIW"¥Õ¯È"NOR, ({ "white paper", "paper" }) );
	set("long", @LONG
[37m¢b¢b¢b¢c¢c¢c¢c¢d¢d¢d¢d¢e¢e¢e¢e¢e¢f¢f¢f¢f¢g¢g¢g¢g¢h¢h¢h¢h¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i
[37m¢i¢i[47;30m2005 Summer Gift By -Alickyuen&Whoami@The.Dream.Of.Seven- [37m¢i[0m
[47;30m¢b¢b¢b¢c¢c¢c¢c¢d¢d¢d¢d¢e¢e¢e¢e¢e¢f¢f¢f¢f¢g¢g¢g¢g¢h¢h¢h¢h¢i¢i¢i¢i[0m

¤@±i¨S¦³¥ô¦ó¹Ï®×ªº¥Õ¯È¡A¥u¦³¥k¤U¨¤¦³¤@¦æ²Ó¦r¡A©Î³\§A¥i¥H¹Á¸Õ¥Î¥¦
¥]¦b¦Û¤v¨­¤W¥ô¦ó¤@³¡¥÷¡E[ ¨Ï¥Î¤èªk¸Ô¨£ help gift ]
[Save EQ]
LONG);
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "±i");
		set("volume", 3);
		set("material", "paper");
	}
	set("no_drop",1);
	set("armor_prop", ([
		"armor"		:	-100,
		"damage"	:	-100,
		"bar"		:	-5,
		"con"		:	100,
	]) );
        set("wear_msg", HIG"$N©Ü¤W$n¤F«á¡A¬ðµM¤@°}¥Õ®ðÄñ¨­¡A¾ã­Ó¤H³£¥Õ¦â¤@¤ù¡I\n"NOR);

	setup();
}

void init()
{
	add_action("do_change", "change");
	add_action("do_help", "help");
}

int do_change(string str)
{ 
	object ob = this_object();

	if( ob->query("equipped") )
		return notify_fail("½Ð¥ý¸Ñ°£¸Ë³Æ¡C\n"); 

	switch(str)
	{ 
		case "head":
		case "mask":
		case "neck":
		case "cloth":
		case "armor":
		case "surcoat":
		case "waist":
		case "shield":
		case "finger":
		case "hands":
		case "legging":
		case "pants":
		case "boots":
			set("armor_type", str);
			message_vision("$N¥ª§é¥k§é§â$n§é¥X¹³"+str+"ªº¼Ò¼Ë¡C\n", this_player(), ob); 
			break;
		default:      
			write("§A¥ª§é¥k§é´N¬O¨S¿ìªk§é¥X³oºØªF¦è¡E\n"); 
			break;
	}

	return 1;
}

int query_autoload() { return 1; }

void setup()
{
	int g,total;
	::setup();
	if( clonep(this_object()) ) return;
	set("armor_type", TYPE_ARMOR); // default type == ARMOR
	if(!query("limit_con")) set("limit_con",weight()/700);
	if(!query("armor_prop/armor")) set("armor_prop/armor",weight()/500);
}

int is_armor(){ return 1; }

int do_help(string str)
{
	if( str == "gift" )
	{
		write(@HELP
«ü¥O®æ¦¡ : change <¨¾¨ãºØÃþ>

§A¥i¥H¨Ï¥Îchange«ü¥O§â¥Õ¯Èªº¨¾¨ã©Ê½è§ïÅÜ¡A§Y¥Õ¯È¥i¥Hwear¦b¨­¤W¥ô¦ó¤@³¡¥÷¡C 

¨¾¨ãºØÃþ¥]¬A :  
head, mask, neck, cloth, armor, surcoat, waist, shield, finger, hands,
legging, pants, boots.

			Written By Sept 2005 -Alickyuen@The.Dream.Of.Seven-

HELP);
		return 1;
	}
}

// end of file
