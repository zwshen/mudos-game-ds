inherit ROOM;
void create()
{
  set("short", "¤u§@Âi®Ç");
  set("long", @LONG

³o¸Ì¬O¤õÄl®Çªº¤@¶ôªÅ¦a¡A³o¸Ì©ñµÛ¤@¶ô¬Ý¨Ó¬Û·í¨I­«
ªº¤jÅK¯z¡A¤WÀYÂ\µÛ¼Æ¶ô¥¼¦¨§ÎªºÅK±ø¡A¦b¤@®Çªº¦a¤W´²¸¨
µÛ¤@¦aªº¥´ÅK¤u¨ã¡A¦pªG¦³»Ý­n¡A±z¥i¥H±NÃa±¼ªºªZ¾¹©Î¸Ë
³Æ¥æµ¹¥´ÅK¦Ñ®v³Õ­×²z [0;1;36m([1mg[1mi[1mv[1me[1m [1mm[1ma[1ms[1mt[1me[1mr[1m [1m<[1mª[1m«[1m«[1m~[1m [1mi[1md[1m>[1m)[0m
LONG
);
  set("exits", ([
  "west" : "/open/world1/tmr/area/smithy",
]));
  set("no_clean_up", 0);

  set("objects",([
__DIR__"eq_master" : 1,
]) );
  set("light",1);
  setup();
  replace_program(ROOM);
}

