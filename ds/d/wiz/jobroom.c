// Room: /d/wiz/jobroom.c

inherit ROOM;

void create()
{
	set("short", "工作進度簡報室");
	set("long", @LONG
這裡是巫師們報告自己工作進度的簡報室﹐同時也是大巫師抓公差
的根據﹐如果你有工作做﹐最好常常到這裡更新你的工作進度﹐如果太
久沒有看到你的工作進度報告﹐大巫師們會以為以沒事做而指派工作給
﹐要是你仍然不理﹐也有可能會被假設成已經放棄巫師的工作而降回玩
家身分。你注意到右邊的牆上新貼了一張[1;37m紙條(Note)[0m。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/wiz/hall1",
]));
	set("no_clean_up", 0);
set("item_desc",([
  "note":@NOTE

============工作進度紀錄板的使用方法如下===============

 新增計劃: project   <標題>
 報告進度: report    <計畫編號> <進度報告標題>
 閱讀計劃: read      <計畫編號>[.<報告編號>]|new|next
 刪除計劃: terminate <留言編號> 

=======================================================
  
PS.因為這個留言板的使用方式有點不太一樣, 所以我貼張紙條
註明一下使用方法.
			-龍蝦(Luky)敬上.1999.7.24.-
NOTE
,]));

	setup();
	call_other("/obj/board/wizard_j", "???");
	replace_program(ROOM);
}
