#include <ansi.h>
inherit NPC;

void auto_sch();

string *stars = ({
  "仙女座",
  "唧筒座",
  "天燕座",
  "天鷹座",
  "寶瓶座",
  "天壇座",
  "白羊座",
  "御夫座",
  "牧夫座",
  "雕具座",
  "鹿豹\座",
  "摩羯座",
  "船底座",
  "仙后座",
  "半人馬座",
  "仙王座",
  "鯨魚座",
  "堰蜓座",
  "圓規座",
  "大犬座",
  "小犬座",
  "巨蟹座",
  "天鴿座",
  "后髮座",
  "南冕座",
  "北冕座",
  "巨爵座",
  "南十字座",
  "烏鴉座",
  "獵犬座",
  "天鵝座",
  "海豚座",
  "劍魚座",
  "天龍座",
  "小馬座",
  "波江座",
  "天爐座",
  "雙子座",
  "天鶴座",
  "武仙座",
  "時鐘座",
  "長蛇座",
  "水蛇座",
  "印地安座",
  "蝎虎座",
  "獅子座",
  "天兔座",
  "天秤座",
  "小獅座",
  "豺狼座",
  "天貓座",
  "天琴座",
  "山案座",
  "顯微鏡座",
  "麒麟座",
  "蒼蠅座",
  "矩尺座",
  "南極座",
  "蛇夫座",
  "獵戶座",
  "孔雀座",
  "飛馬座",
  "英仙座",
  "鳳凰座",
  "繪架座",
  "南魚座",
  "雙魚座",
  "船艫座",
  "羅盤座",
  "網罟座",
  "玉夫座",
  "天蝎座",
  "盾牌座",
  "巨蛇座",
  "六分儀座",
  "天箭座",
  "人馬座",
  "金牛座",
  "望遠鏡座",
  "南三角座",
  "三角座",
  "杜鵑座",
  "大熊座",
  "小熊座",
  "船帆座",
  "室女座",
  "飛魚座",
  "狐狸座",
});
  

string *stars_eng = ({
  "Andromeda",
  "Antlia",
  "Apus",
  "Aquila",
  "Aquarius",
  "Ara",
  "Aries",
  "Auriga",
  "Bootes",
  "Caelum",
  "Camelopardalis",
  "Capricornus",
  "Carina",
  "Cassiopeia",
  "Centaurus",
  "Cepheus",
  "Cetus",
  "Chamaeleon",
  "Circinus",
  "Canis Major",
  "Canis Minor",
  "Cancer",
  "Columba",
  "Coma Berenices",
  "Corona Australis",
  "Corona Borealis",
  "Crater",
  "Crux",
  "Corvus",
  "Canes Venatici",
  "Cygnus",
  "Delphinus",
  "Dorado",
  "Draco",
  "Equuleus",
  "Eridanus",
  "Fornax",
  "Gemini",
  "Grus",
  "Hercules",
  "Horologium",
  "Hydra",
  "Hydrus",
  "Indus",
  "Lacerta",
  "Leo",
  "Lepus",
  "Libra",
  "Leo Minor",
  "Lupus",
  "Lynx",
  "Lyra",
  "Mensa",
  "Microscopium",
  "Monocers",
  "Musca",
  "Norma",
  "Octans",
  "Ophiuchus",
  "Orion",
  "Pavo",
  "Pegasus",
  "Perseus",
  "Phoenix",
  "Pictor",
  "Piscis Australis",
  "Pisces",
  "Puppis",
  "Pyxis",
  "Reticulum",
  "Sculptor",
  "Scorpius",
  "Scutum",
  "Serpens",
  "Sextans",
  "Sagitta",
  "Sagittarius",
  "Taurus",
  "Telescopium",
  "Triangulum Australe",
  "Triangulum",
  "Tucana",
  "Ursa Major",
  "Ursa Minor",
  "Vela",
  "Virgo",
  "Volans",
  "Vulpecula",
});

string *replace_stars = ({
  "And",
  "Ant",
  "Aps",
  "Aql",
  "Aqr",
  "Ara",
  "Ari",
  "Aur",
  "Boo",
  "Cae",
  "Cam",
  "Cap",
  "Car",
  "Cas",
  "Cen",
  "Cep",
  "Cet",
  "Cha",
  "Cir",
  "CMa",
  "CMi",
  "Cnc",
  "Col",
  "Com",
  "CrA",
  "CrB",
  "Crt",
  "Cru",
  "Crv",
  "CVn",
  "Cyg",
  "Del",
  "Dor",
  "Dra",
  "Equ",
  "Eri",
  "For",
  "Gem",
  "Gru",
  "Her",
  "Hor",
  "Hya",
  "Hyi",
  "Ind",
  "Lac",
  "Leo",
  "Lep",
  "Lib",
  "LMi",
  "Lup",
  "Lyn",
  "Lyr",
  "Men",
  "Mic",
  "Mon",
  "Mus",
  "Nor",
  "Oct",
  "Oph",
  "Ori",
  "Pav",
  "Peg",
  "Per",
  "Phe",
  "Pic",
  "PsA",
  "Psc",
  "Pup",
  "Pyx",
  "Ret",
  "Scl",
  "Sco",
  "Sct",
  "Ser",
  "Sex",
  "Sge",
  "Sgr",
  "Tau",
  "Tel",
  "TrA",
  "Tri",
  "Tuc",
  "UMa",
  "UMi",
  "Vel",
  "Vir",
  "Vol",
  "Vul",
});

string *chinese_stars = ({
  "螣蛇、天廄、璧宿、奎宿、軍南門、天大將軍",
  "唧筒、在張宿南",
  "異雀、近南極",
  "天弁、右旗、左旗、河鼓、天桴、離珠、天巿左垣",
  "女宿、虛宿、天壘城、危宿、司命、蓋屋、墳墓、哭、泣、虛梁、壘璧陣、羽林軍、鈇金戊",
  "杵、龜",
  "婁宿、左更、胃宿、天陰",
  "五車、柱、天潢、咸池、八穀、座旗",
  "大角、右攝提、左攝提、元戈、帝席、招搖、梗河、七公、天槍、亢池",
  "近天園",
  "紫微右垣、六甲",
});

void create()
{
        int x = random(sizeof(stars));
        set_name(HIW" 星座 "NOR + HIR"[ " + stars[x] + " ] "NOR, ({ "Star: " + stars_eng[x], "stars", "star", stars_eng[x] }));
        set("long", "這是一群" + stars[x] + "的小群星們 ( 你可以用 list_stars 來看目前所有的星座 )。\n");

        set("race", "機器人");

        set("chat_chance", 20);
  
        set("level", 100);

        set("unit", "個");
        set("no_fight", 1);
        set("value", 1);

        set("schedule", ([
  "00" : (: auto_sch :),
  "12" : (: auto_sch :),
]));

        setup();
}

void init()
{
        if( this_player() == environment(this_object()) )
                this_object()->move(environment(this_player()));
        if( this_player()->query("id") == "cominging" )
                call_out("meet", 2, this_player());
        add_action("do_list_stars", "list_stars");
}

void die()
{
        return;
}

int talk_action(object me)
{
        command("sigh");
        command("say 好無奈.. 我愛她, 她不愛我, 我.... ");
        command("cry " + me->query("id") );
        return 1;
}

void auto_sch()
{
        object new_stars = new(__FILE__);
        message_vision(HIB"$N暗淡的顯示出： 唉... 我愛妳, 我親愛的妳, 但是, 我永遠不能和妳在一起.... \n"NOR, this_object());
        message_vision(HIB"$N有點灰心的樣子, ”也許, 人, 要靠緣份的.... ”\n"NOR, this_object());
        message_vision(HIB"”在今年的情人節, 我過的好痛苦, 好悲傷, 對著自己痛痛的哭, 永遠.. 永遠.. ”\n"NOR, this_object());
        message_vision(HIR"$N在這之後, 便拿出了一把滅情刀, 閃閃發亮.. \n"NOR, this_object());
        message_vision(HIC"只見$N消失在這個世界中, 似乎到了另一個世界... \n"NOR, this_object());
        new_stars->move(environment(this_object()));
        destruct(this_object());
}

int do_list_stars(string arg)
{
        object me = this_player();
        string msg = "\n\n  號碼│代號│　　學　　名　　│ 譯  名 │中國古代中文別稱\n" +
		     "───┼──┼────────┼────┼───────────────\n",
               chn;
        int i;

        for(i=0;i<sizeof(stars);i++)
        {
                if( i > (sizeof(chinese_stars)-1) )
			msg += sprintf("   %-3d│%4s│%16s│%8s│\n", i+1, replace_stars[i], stars_eng[i], stars[i]);
                if( i <= (sizeof(chinese_stars)-1) )
			msg += sprintf("   %-3d│%4s│%16s│%8s│%s \n", i+1, replace_stars[i], stars_eng[i], stars[i], chinese_stars[i]);
                msg+= "───┼──┼────────┼────┼───────────────\n";
        }
        msg += "───┴──┴────────┴────┴───────────────\n\n";
        me->start_more(msg);
        return 1;
}

void meet(object me)
{
        command("say Johnny, 你來了呀... ");
        command("jump cominging");
        tell_object(me, HIC" - 你過的好嗎 ? \n"NOR);
        me->set_temp("spell/bless", 100);
}
