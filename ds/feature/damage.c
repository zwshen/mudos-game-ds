// File : "/feature/damage.c"
// Backup : "/feature/damage.20011110"

// tmr 2007/03/01
// Fix Bug: ���������~�Ӧ��`�ɡA���ݭnclear condition

// alickyuen@ds 2001-11-10
// Change : ���die()�����������~����

// #pragma save_binary
#include <ansi2.h>
#include <dbase.h>
#include <login.h>
#include <move.h>
#include <command.h>

#define PK_AREA "/open/world1/alickyuen/match/area"

void die_step(int flag);

int ghost = 0;

int is_ghost() { return ghost; }

// �p�G���N�vitem���ܡA�h�i�H����ͩR�Ȫ��ˮ`�Adamage = 0
// �_�h���ܡAdamage�����쥻���Ȥ���
int compensate_damage(int damage) {
    object pet;

    if( !objectp(pet = present("COMPENSATORY_ITEM", this_object() ) ))
        return damage;

    // �qpet�����ˮ`
    pet->add("hp", - damage);

    // �i�����Ҧ����ˮ`��
    if( pet->query("hp") > 0 )  return 0;

    // pet ���ͩR�Χ��F
    message_vision(HBK"$N"HBK"���W��$n"HBK"�A�]�L�k�N��$N"HBK"�Ө��ˮ`�A�ư��@�}���ϡA���������F�C\n"NOR, this_object(), pet );

    // �S������damage �A�ٻݭn���this_object���W
    damage = -pet->query("hp");
    destruct(pet);
    return damage;
}

// add by -Acme- 2007.01.09
int receive_damage_buffer_effect(string type, int damage, object who)
{
    // �o�����ӭn���h�@�ت���
    // ��n������sk�ݭn�Ұ� receive_damage_buffer_effect ���\��
    // ���Ȯɳo�˼g  -Acme-

    if( this_object()->query_skill("buddha-body") )
        damage = "/daemon/skill/buddha-body.c"->receive_damage_buffer_effect(type, damage, this_object(), who);

    return damage;
}
// �����v�v�T
	
int hit_power(int damage, object who) {
	int hit, power;
	if(!objectp(who)) return damage;
	if( who == this_object() ) return damage;
	
	// �ĤH�������v - �ڪ��z����ܲv
	hit = who->query_hit() - this_object()->query_hit_against();
	if( hit <= 0 ) return damage;
	if( hit > 50 ) hit = 50; // �̰�50%
	if( random(100) > hit ) return damage;
	
	// �z������
	power = who->query_hitpower();
	damage = damage + (damage * power)/100;
    message_vision(BRED+HIY"$N"BRED+HIY"��$n"BRED+HIY"�y���@���D�`�P�R���ˮ`("+damage+")�I�I�I\n"NOR, who, this_object());
	return damage;	
}

varargs int receive_damage(string type, int damage, object who)
{
    int val;

    if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
    if( type!="hp" && type!="mp" && type!="ap" )
        error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");

    if( objectp(who) && type=="hp") {
        // �u�w��ͩR�Ȱ��B�z
        if(who!=this_object()) damage = compensate_damage(damage);
        set_temp("last_damage_from", who);
    }

    // add by -Acme-
    damage = receive_damage_buffer_effect(type, damage, who);
    if( type == "hp" ) 
    	damage = hit_power(damage, who);

    val = (int)query(type) - damage;

    if( val >= 0 ) 
    	set(type, val);
    else 
    	set( type, -1 );
    
    if( type == "hp")
    {
        if(query_temp("power_exert") > 0 ) add_temp("power_exert",-1);
        if(query_temp("power_cast") > 0 ) add_temp("power_cast",-1);
        if( val <= 1 )
            message_vision(HIR"$N"HIR"�w�g�R�b���i�A�p�G���A�Q�I��k�A$N"HIR"�N�n�ǳƥh���Fù���U���o�C\n"NOR,this_object());
        else {
            delete_temp("temp/death_type");
            delete_temp("last_damage_from");
        }
    }

    if(query_temp("sleeping")) this_object()->wakeup(0);
    if( !query_heart_beat(this_object()) ) set_heart_beat(1);

    return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
    string *body_limbs;
    int val;

    if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
    body_limbs=query("limbs");
    if(sizeof(body_limbs)<1) return 0;
    if( type == "random")
    {
        val = random(sizeof(body_limbs));
        type=body_limbs[val];
    }
    if( member_array(type,body_limbs) == -1) return 0;
    if( objectp(who) ) set_temp("last_damage_from", who);
    if((int)query("wound/"+type)==100) return 0;

    val = (int)query("wound/"+type) + damage;
    if( val > 100) val =100;
    if( val > 0 ) set("wound/"+type, val);
    else
    {
        set("wound/"+type, 0 );
        val = 0;
    }
    if(query_temp("power_exert") ) set_temp("power_exert",0);
    if(query_temp("power_cast") ) set_temp("power_cast",0);
    set("heart_modify",1);
    if( !query_heart_beat(this_object()) ) set_heart_beat(1);
    if(damage > 0) message("system", HIR "\n�A��"+to_chinese(type)+"�@�}�@�h�A�ݨӨ��ˤ����C("+val+"%)\n\n" NOR,this_object());
    if(query_temp("sleeping")) this_object()->wakeup(0);
    return damage;
}

varargs int receive_heal(string type, int heal)
{
    int val;

    if( heal < 0 ) error("F_DAMAGE: ��_�Ȭ��t�ȡC\n");
    if( type!="hp" && type!="mp" && type!="ap" && type!="all" )

        error("F_DAMAGE: ��_�������~( �u��O hp, mp, ap �䤤���@ )�C\n");
    if(type=="all")
    {
        this_object()->receive_heal("hp",heal);
        this_object()->receive_heal("mp",heal);
        this_object()->receive_heal("ap",heal);
        return heal;
    }
    val = (int)query(type) + heal;

    if( val > (int)query("max_"+type) ) set(type, (int)query("max_"+type));
    else set( type, val );
    if( !query_heart_beat(this_object()) ) set_heart_beat(1);
    return heal;
}

varargs int receive_curing(string type, int heal)
{
    int val,check,i,j;
    string *body_limbs;

    if( heal < 0 ) error("F_DAMAGE: �����Ȭ��t�ȡC\n");
    body_limbs=query("limbs");

    j=sizeof(body_limbs);
    if(j<1) return 0;

    if(type=="all")
    {
        for(i=0;i<j;i++) this_object()->receive_curing(body_limbs[i],heal);
        return heal;
    }
    if( member_array(type,body_limbs) == -1) return 0;
    val = (int)query("wound/"+type) - heal;
    if((int)query("wound/"+type)>0 && heal> 0 ) check = 1;
    if( val < 0 ) val = 0;
    if( val > 100 ) val = 100;
    set("wound/"+type, val );
    set("heart_modify",1);
    if( !query_heart_beat(this_object()) ) set_heart_beat(1);
    if(check)
    {
        if(val==0) message("system", HIW "\n�A"+to_chinese(type)+"���ˤf������¡�F�C\n" NOR,this_object());
        else message("system", HIW "\n�A�Pı"+to_chinese(type)+"���ˤf�n�F�@�ǡC\n" NOR,this_object());
        return heal;
    } else return 0;
}

varargs void unconcious()
{
    remove_call_out("unconcious");
    if( !living(this_object()) ) return;
    if( wizardp(this_object()) && query("env/immortal") )
    {
        this_object()->set("hp",this_object()->query("max_hp"));
        return;
    }
    if( query_temp("unconcious") ) return;
    //  if( objectp(defeater = query_temp("last_damage_from")) )
    //          COMBAT_D->winner_reward(defeater, this_object());

    this_object()->remove_all_enemy();

    message("system", HIR "\n�A�����e�@�¡M���ۤ���]�����D�F....\n\n" NOR,
            this_object());
    this_object()->disable_player_cmds("�A���b���g�A�����H�ơC\n");
    //this_object()->disable_player(" <�����H��>");
    set("hp", 0);
    set("mp", 0);

    set_temp("block_msg/all", 1);
    COMBAT_D->announce(this_object(), "unconcious");
    call_out("revive", random(10) + 8);
}

varargs void revive(int quiet)
{
    remove_call_out("revive");
    remove_call_out("die");
    while( environment()->is_character() )
        this_object()->move(environment(environment()));
    this_object()->enable_player();
    this_object()->enable_player_cmds();
    if( !quiet )
    {
        COMBAT_D->announce(this_object(), "revive");
        set_temp("block_msg/all", 0);
        message("system", HIY "\n�C�C�a�A�ש�S���F��ı....\n\n" NOR,
                this_object());
        if(wizardp(this_object()) && userp(this_object())) this_object()->set("hp",this_object()->query("max_hp"));
    } else
    {
        set_temp("block_msg/all", 0);

        this_object()->move(environment());
        //command("look");
    }
}

void die()
{
    object corpse, killer,*inv,ride,doll;
    int i;
    string undead_msg, start_place, wimpy_msg; // add start_place & wimpy_msg by -alickyuen@ds-

    remove_call_out("die");
    remove_call_out("revive");

    //if( !living(this_object()) ) revive(1);
    if( wizardp(this_object()) && query("env/immortal") ) { revive(); return; }

    killer = this_object()->query_temp("last_damage_from");


    // tmr 2007/03/01
    // Fix Bug: ���������~�Ӧ��`�ɡA���ݭnclear condition
    // Clear all the conditions by death.
    //this_object()->clear_condition();
    this_object()->clear_map_skill(1);

    if( strsrch(file_name(environment(this_object())), PK_AREA) != -1 )
    {
        // PK ��
        this_object()->set("hp", this_object()->query("max_hp")/2 );
        this_object()->set("ap", this_object()->query("max_ap")/2 );
        this_object()->set("mp", this_object()->query("max_mp")/2 );
        this_object()->move("/open/world1/alickyuen/match/exit.c");
        return;
    }

    /////////////////////////////////////////////////////////////////////
    //��������
    if(doll = present("undead_item",this_object()))
    {
        if(stringp(undead_msg=doll->query("undead_msg")))
            message_vision(undead_msg,this_object(),doll);
        else message_vision(HIG"\n\n�N�b�d�v�@�v����, $N���W��$n��M�ĥX�צ�F�o�P�R�@��!!\n\n",this_object(),doll);

        this_object()->reincarnate();
        if( objectp(killer) )
        {
            if( stringp(wimpy_msg = doll->query("wimpy_msg")))
                message_vision(wimpy_msg,this_object(),doll);
            else message("system",HIW"\n\n "+killer->query("name")+HIW"���㪺�j�q�G�i�c��"+this_object()->name(1)+HIW"! ���M�o�����A�k�L�@�T! ���`���@�ѧڷ|����A��!!\n\n"NOR,users());
        } else message("system",HIW"\n\n ����ǨӤ@�}�q�s�n�G�i�c��"+this_object()->name(1)+HIW"! ���M�o�����A�k�L�@�T! ���`���@�ѧڷ|����A��!!\n\n"NOR,users());

        if(stringp(start_place=doll->query("start_place")))
            this_object()->move(load_object(start_place));
        else RECALL_CMD->do_move(this_object(),"start");
        // �� doll �O��
        log_file("DOLL_DIE",
                 sprintf("%s(%s) lost doll [%s] on %s\n",
                         this_object()->query("name"),           //�H�W
                         this_object()->quer("id"),              //ID
                         doll->query("name"),    //doll
                         ctime(time()) ) );              //�ɶ�
        destruct(doll);

        this_object()->save();
        return;
    }

    ///////////////////////////////////////////////////////////////////////
    // �H�U�O�����ڦ��`��A�n�B�z���Ʊ�

    // Clear all the conditions by death.
    this_object()->clear_condition();

    if(ride=this_object()->query_temp("ride"))
    {
        message_vision("$N�q"+ride->name(1)+"�W�^�F�U�ӡC\n",this_object());

        ride->delete_temp("riden");
        ride->move(environment(this_object()));
        this_object()->delete_temp("ride");
    }

    COMBAT_D->announce(this_object(), "dead");

    if( objectp(killer) )
    {
        set_temp("my_killer", killer->query("id"));
        //killer->set_temp("kill_together",this_object()->query_enemy());
        COMBAT_D->killer_reward(killer, this_object());
    }

    inv = all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++)
    {
        if(inv[i]->query("equipped"))
        {
            //  if(inv[i]->query("skill_type")) UNWIELD_CMD->main(this_object(),inv[i]->query("id"));
            //          else REMOVE_CMD->do_remove(this_object(),inv[i]);
            //  if(inv[i]->query("equipped")) inv[i]->unequip();
            if(!inv[i]->query("no_drop")) inv[i]->unequip();

        }
    }

    if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
    {
        corpse->move(environment());
        if(userp(this_object())) corpse->set("owner_id",query("id"));
        if( !userp(this_object()) && this_object()->query("level") > random(500) )
            corpse->animate(killer, time() );
    }
    if(userp(this_object()) && !wizardp(this_object()))
    {
        this_object()->skill_death_penalty();
        this_object()->spell_death_penalty();
        if( this_object()->query_temp("killer") )
            this_object()->add("popularity",-25);
        this_object()->save();
    }
    this_object()->remove_all_enemy();
    this_object()->remove_all_killer();
    this_object()->disable_player_cmds("�A�w�g���F�A�S������C\n");
    if( objectp(killer) ) killer->remove_killer(this_object());


    //�R���S��Ȧs���
    this_object()->delete_temp("apply");        //�˳ƤΧޯ�W�j�ĪG (�ݩʤΧޯ�)
    this_object()->delete_temp("spell");        //�k�N�ĪG (�ݩ�)
    this_object()->delete_temp("is_busy");      //�L�k���ʮɪ��аO
    this_object()->delete_temp("exert_mark");//�ޯ�μȦs����(�Ův�ۥѨϥ�)
    this_object()->delete_temp("spell_mark");//�k�N�μȦs����(�Ův�ۥѨϥ�)
    this_object()->delete_temp("quest");        //���Ȱʧ@�B�J�Ȯɬ���(�Ův�ۥѨϥ�)
    this_object()->delete_temp("temp");         //�Ȧs���� (�Ův�ۥѨϥ�)
    this_object()->delete_temp("skill_active");//�t�ΧP�_��, �Ův�Ű�.
    this_object()->delete_temp("sleeping");
    this_object()->delete_temp("invader");  //����M���I���̼аO
    this_object()->delete_temp("killer"); //����M�����H�ǼаO
    //�b�����H�����������
    all_inventory(environment())->remove_killer(this_object());

    this_object()->dismiss_team();

    if( userp(this_object()) )
    {
        set("hp", 1);
        set("mp", 1);
        ghost = 1;
        set_temp("block_msg/all", 0);

        this_object()->disable_player(" <�@�L�I�l>");
        this_object()->move(DEATH_ROOM);
        message("vision",
                "�A���M�o�{�e���h�F�@�Ӱ��v�M���L���v�l�S�n���w�g�b����\n"
                "�ܤ[�F�M�u�O�A�@���S�oı�C\n", environment(), this_player());
        this_object()->save();
        set_temp("block_msg/all", 0);
        this_object()->disable_player(" <�@�L�I�l>");
        tell_object(this_object(),"�A���F...\n�A���F�����}�F�A������.. �Pı�����ƪ�.. \n\n");
        call_out("die_step",5,2);
        //DEATH_ROOM->start_death(this_object());
    } else
        destruct(this_object());

}

void die_step(int flag)
{
    if(flag<1)
    {
        tell_object(this_object(),"���L�ت��a�ƿ��F�@�q�ɶ�.. �A�ש�S�^��F���x������.. \n\n");
        revive(1);
        this_object()->enable_player_cmds();

        return;
    }

    if(flag==2) tell_object(this_object(),"��...�@�f�ä��..�A�ש��٬O���F....  \n\n");
    else if(flag==1) tell_object(this_object(),"�L�h�������@���������_�X�{�b�A��������..  \n\n");
    else tell_object(this_object(),"�A�ݨ�o�y�ܴN��ܦ�bug�F..�Х�guest���slogin..   \n\n");

    call_out("die_step",7,--flag);
    return;

}

varargs void reincarnate()
{
    ghost = 0;
    set("hp", query("max_hp"));
    set("mp", query("max_mp"));
    set("ap", query("max_ap"));
    if(query("wound")) delete("wound");
}

int max_food_capacity() { return query_weight() / 200; }


int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
      int update_flag, cure_count;
    int q_con;
    int q_int;
    int F_degree = 10;
    mapping my;
    if( !this_object() ) return 0;
    //  if( this_object()->is_fighting() ) return 1;

    if( this_object()->is_fighting() ) F_degree = 20;

    update_flag = 0;

    my = query_entire_dbase();

    q_con = this_object()->query_con();
    q_int = this_object()->query_int();
    if( userp( this_object() ) )
    {
        if(this_object()->query("talk_point") < (5 + my["level"]*3) ) this_object()->add("talk_point",1+my["level"]/15);

        if(my["supply_point"] < ( my["level"]*20 + 40 ) ) my["supply_point"] += 2+my["level"]/4;

        if( ! this_object()->is_fighting() )    // �S���԰��~��_
        {
            my["hp"] += q_con / F_degree + 2 +this_object()->query_temp("add_hp");
            my["mp"] += q_int / F_degree + 2 +this_object()->query_temp("add_mp");
            my["ap"] += q_con / F_degree + 2 +this_object()->query_temp("add_ap");
        }
    }
    else        // ���O���a�ҭn�����ʧ@
    {
        if( ! this_object()->is_fighting() )    // �S���԰��~��_
        {
            my["hp"] += 1 + my["con"]/F_degree ;
            my["mp"] += 1 + my["int"]/F_degree ;
            my["ap"] += 1 + my["con"]/F_degree ;
        }
        if( my["combat_exp"] > (my["level"]+1)*(1+my["exp_point"])*500)
            my["combat_exp"] = (my["level"]+1)*(1+my["exp_point"])*500;

    }

    if( my["hp"] >= my["max_hp"] ) my["hp"] = my["max_hp"];

    else update_flag++;

    if( my["mp"] >= my["max_mp"] ) my["mp"] = my["max_mp"];
    else update_flag++;

    if( my["ap"] >= my["max_ap"] ) my["ap"] = my["max_ap"];
    else update_flag++;

    switch(my["race"])
    {
    case "zerg":
        cure_count=14;
        break;
    case "protoss":
        cure_count=24;
        break;
    default:
        cure_count=18;
    }

    if( my["cure_count"] > cure_count  )
    {
        this_object()->receive_curing("all",1);

        my["cure_count"]=0;
    } else      my["cure_count"]++;

    //let room can have special action while heal_up time
    //add_by Luky
    /* Move to char.c heart_beat() - tmr 2006/11/19
    if( environment(this_object()) ) {
    if(environment()->room_effect(this_object())) update_flag++;
    }
    */

    return update_flag;
}
