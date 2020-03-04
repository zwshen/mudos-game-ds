#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","§ø¤l¤¤");
	set("long","\n"
WHT"¢© \n"NOR
WHT"¢¥¢©\n"NOR
WHT"¢¥¢¦¢©\n"NOR
WHT"¢¥¢¦¢¦¢©—l—l—l—l—l—l—l—l  ¡ó\n"NOR
WHT"¢¥¢¦¢¦¢¦¢§—l—l—l—l—l—l—l¡ò¡ò¡ò\n"NOR
WHT"¢¥¢¦¢¦¢E¢§—l—l—l—l—l—l—l—l¡ò\n"NOR
WHT"¢¥¢¦¢¦¢¦¢§—l—l—l—l—l—l—l¡ò  ¡ò\n"NOR
WHT"¢¥¢¦¢¦¢¦¢§¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_¡_\n"NOR
"\n"
"³o¸Ì¬O­×¼w§øªº§ø¤l¸Ì¡A¦b¥k¤âÃä¦³¦n´X´É­T«Î¡A¥V·x®L²D¬O­T«Îªº¯S\n"
"¦â¡A¦A¥[¤W³o¸Ì§ø¥Á­·±¡¶}®Ô¡A¤H¥Á¦Y³Ü¤£·T¡A¥O§A¦³¤@ÂI·Q­n¦b³o¸Ì\n"
"©~¦í¤U¨Óªº·N«ä¡A¶Æ¨R§ø¤D¬O°­Â_´ËªLªº°_ÀY¡A¦]¦¹¦b³o¦³³\\¦h¹L¸ôªº\n"
"®È«È¸g¹L¡A¨Ã¥B¦³³\\¦h¸É¥R­¹ª«©M¸Ë³Æªº¦a¤è¡C\n");
	set("exits",([
  "west": __DIR__"village",
]));
	set("objects",([
  __DIR__"npc/villager.c" : 1,
]));
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
