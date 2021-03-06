// Room: /daemon/class/scholar/entrance.c

inherit ROOM;

void create()
{
	set("short", "曼雩台");
	set("long", @LONG
這裡是雨橋莊西邊的曼雩台﹐也是喬陰縣城的文人墨客時常聚集談
論詩文的地方﹐台寬約十丈﹐西邊是連接喬陰縣城的翠柳曲橋﹐從翠柳
湖中的片片睡蓮中彎彎曲曲地通往西邊的廣場﹐北邊和南邊各有數十根
樑柱﹐常有許多落拓的士人將他們的作品貼在這裡希望得到貴人賞識﹐
往東是一片桃樹林﹐春天時和翠柳湖畔的柳樹相輝映﹐蔚為喬陰縣的第
一盛景。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/choyin/bridge5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
