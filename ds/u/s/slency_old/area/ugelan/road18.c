// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "巴洛克廣場");
	set("long", @LONG
這裡是此城中心的一座大型廣場，正中央有一座噴水池，有不少人
圍坐在水池旁聆聽著街頭藝人的音樂表演，附近傳來陣陣的咖啡香令人
酣醉，廣場北邊有一座平台，每逢假日節慶，宮廷樂師都會來此表演, 
這是查理斯國王愛護居民的具體表現，居民對此活動也都十分熱烈參與
，藉此也消除不少貴族與平民的隔閡，往南是一間旅店，往北則通往皇
宮。
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road5",
  "south" : __DIR__"inn",
]));
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/obj/pot" : 1,
]));

 	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}