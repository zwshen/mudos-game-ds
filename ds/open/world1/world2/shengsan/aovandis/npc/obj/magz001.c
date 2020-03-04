// ¥i¼v¦LªºÂø»x
inherit ITEM;

void create()
{
	set_name("¹Ú¤Û¶g¥Z",({"dream magazine","magazine","dream"}) );
	set("long",@LONG
¹Ú¤Û¶g¥Z¹Ú¤Û¶g¥Z			¹Ú¤Û¶g¥Z		¡À
¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z
¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z
¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z
¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z		¹Ú¤Û¶g¥Z
¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z			¹Ú¤Û¶g¥Z
¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z
¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z	¹Ú¤Û¶g¥Z
¹Ú¤Û¶g¥Z¹Ú¤Û¶g¥Z			¹Ú¤Û¶g¥Z
LONG
	);
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",220);
		set("unit","¥»");
	}

	setup();
}

int can_copy()
{
	return 1;
}

int is_magzine()
{
	return 1;
}

