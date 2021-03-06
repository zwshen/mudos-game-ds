// Room: /d/shaolin/zhulin.c

//inherit VRM_SERVER;

inherit "/adm/daemons/virtual/vrm_server";
void create()
{
	// 迷宮房間所繼承的物件的檔案名稱。
	set_inherit_room( ROOM );

	//迷宮房間里的怪物。
	//set_maze_npcs(__DIR__"npc/maque");

	//迷宮的單邊長
	set_maze_long(20);

	//入口方向(出口在對面)
	set_entry_dir("east");

	//入口與區域的連接方向
	set_link_entry_dir("east");

	//入口與區域的連接檔案名
	set_link_entry_room(__DIR__"shandao3");

	//出口與區域的連接方向
	set_link_exit_dir("west");

	//出口與區域的連接檔案名
	set_link_exit_room(__DIR__"muwu");

	//入口房間短描述
	set_entry_short("山道旁");

	//入口房間描述
	set_entry_desc(@LONG
這里是少室山的半山腰，東面是一條陡直的山道，向西面望
去是一片翠綠的竹林，不時傳來聲聲鳥鳴。
LONG
);

	//出口房間短描述
	set_exit_short("碎石路");

	//出口房間描述
	set_exit_desc(@LONG
這里是一條碎石小路，東面是一片翠綠的竹林，不時傳來聲
聲鳥鳴。向西望去隱約一間小木屋，依山傍林，真是一處世外桃
源神仙所在。
LONG
);

	//迷宮房間的短描述
	set_maze_room_short("竹林");

	//迷宮房間的描述，如果有多條描述，制造每個房
	//間的時候會從中隨機選擇一個。
	set_maze_room_desc(@LONG
這是一片濃密的翠竹林，小鳥的鳴叫聲和風吹過竹林的沙沙
聲交織成美麗的大自然的旋律。地上雜草叢生說明這里很少有人
來。粗壯的翠竹筆直向上，這就是天下聞名的南翠竹。
LONG
);

	// 迷宮房間是否為戶外房間？
	set_outdoors(1);
}
