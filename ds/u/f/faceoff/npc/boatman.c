#include <ansi.h>
inherit NPC;
void create()
{
 set_name("船老大",({"boat man","man"}));
 set("long","他是無砂港通往扶桑一帶的船夫。\n");
 set("age",41);
 set("gender","男性");
 set("level",10);
 set("chat_chance",20);
 set("chat_msg", ({"船老大氣呼呼的說: 船沒開是老子的錯? 有種的就跟老子幹上一架!.\n",
	           "船老大氣呼呼的說: 去問海政司的龜兒子們啦! 他媽的, 一張簽出條也發不下來.\n",
                            (:command("pig"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","怎麼樣? 又來一個怪老子的? 他媽的"+HIG+"謝基"+NOR+"......!\n"NOR);

	set("inquiry/謝基","就是那個兔崽子! 誰敢當面跟他說"+HIG+"韃靼舟"+NOR+", 保證龜兒子連屁也放不出一個!\n"NOR);

	set("inquiry/韃靼舟","就是這艘船的舟號啦! 要不是海政司那批吃白飯的, 怎會連一張"+HIG+"簽出條"+NOR+"有發不出來?.\n"NOR);

	set("inquiry/簽出條","那也是海政司那批人發出來的鬼東西! 偏偏又不發給咱們, 根本是純心找喳....\n");


 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}

