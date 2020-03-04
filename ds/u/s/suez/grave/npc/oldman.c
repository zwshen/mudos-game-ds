inherit NPC;
void create()
{
set_name("老人",({"oldman"}));
set("long",@LONG

長袖寬衣，腰帶拖地，手持一壺酒，小酌為狂飲，醉時高歌不成調，
醒時吟詩且得意，只配劍鞘不配劍，只舞月影與秋音，客來何拘束？
客去莫傷心，來去本為人間事，君不見？白頭成黃髮，去年秋燕去，
今年子歸啼。

LONG
);
     set("age",70);

     set("level", 77);
     set("chat_chance",7);
     set("gender","男性");
     set("chat_msg",({
     "老人吟到：「醉看紅塵，方寸之間多紛爭。」\n",
     "老人吟到：「笑談古今，將相之塚草青青。」\n",
     "老人突然哈哈大笑數聲，拿起酒葫蘆就喝了一大口。\n"
      }));
     set("attitude", "peaceful");
     set("talk_reply","來來來！陪我喝杯酒，今天不醉不歸！");

     setup();
     add_money("coin", 1700);
}
