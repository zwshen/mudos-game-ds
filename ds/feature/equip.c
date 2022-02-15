/*
  Name: /feature/equip.c
  Copyright: DS2
  Author: Alickyuen
  Date: 04/08/05 02:00
  Description: 
*/

/** 
  * Last update by Tmr 2006/11/11
  * �[�W�s�رڤι�˳ƪ�����
  */

// #pragma save_binary
#include <dbase.h>
#include <weapon.h>

int wear()
{
        object owner,weapon,armor;
        mapping armor_prop, applied_prop;
        string *apply, type,race_armor_prop,race_armor_type,race;
        int flag;
        
        // Only character object can wear armors.
        owner = environment();
        if(!owner) 
        {
                log_file( "debug", "/feature/equip.c ERROR in wear():\n"+
                        this_object()->query("name") + "["+base_name(this_object())+"] �S�����ҵL�k�˳�. at:" + ctime(time()) + "\n" );
                return 0;
        }
        if( !owner->is_character() ) return 0;
        
        // If already worn, just recognize it.
        if( this_object()->query("equipped") ) return 1;

        // Find owner's Race
        switch( owner->query("race") )
        {
                case "���~" :
                case "beast" :
                                race_armor_prop="beast_armor_prop";
                                race_armor_type="beast_armor_type";
                                break;
                case "���~" :
                case "monster" :
                                race_armor_prop="monster_armor_prop";
                                race_armor_type="monster_armor_type";
                                break;
                default : // default �����
//                        return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�ä��A�X"+owner->query("race")+"�ϥΡC\n");
                                        race_armor_prop="armor_prop";
                                        race_armor_type="armor_type";
                                break;

        }

        // Check if we have "armor_prop" defined.
        if( !mapp(armor_prop = this_object()->query(race_armor_prop)) )
                return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�ä����D�Ӧp��ϥΡC\n");
                
        //�l�a
        if( this_object()->is_broken() ) 
                return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�l�a�F�C\n");
        
        if( this_object()->query_temp("no_energy") ) 
                return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�S����q�F�C\n");       
        
        // Check if twohand all used
        if(weapon=owner->query_temp("weapon"))
        {
                flag = weapon->query("flag");
                if( flag & TWO_HANDED )
                {
                        if( this_object()->query(race_armor_type)=="shield" )
                                return notify_fail("�A�������ťX�@����~��˳�"+this_object()->name()+"�C\n");
                }
                if(owner->query_temp("secondary_weapon"))
                {
                        if( this_object()->query(race_armor_type)=="shield" )
                                return notify_fail("�A�������ťX�@����~��˳�"+this_object()->name()+"�C\n");
                }
        }
        
        type = this_object()->query(race_armor_type);
        if( armor = owner->query_temp("armor/" + type) )
                return notify_fail("�A���������U"+armor->name()+"�A�~��˳�"+this_object()->name()+"�C\n");
        
        // �رڭ���
        if( !RACE_D( owner->query("race") )->can_wear(type) )
                return notify_fail("�A���رڵL�k�ϥγo�Ӹ˳ơC\n");

        owner->set_temp("armor/" + type, this_object());
        apply = keys(armor_prop);
        applied_prop = owner->query_temp("apply");
        if( !mapp(applied_prop) ) applied_prop = ([]);
        for(int i = 0; i<sizeof(apply); i++) {
                if( undefinedp(applied_prop[apply[i]]) )
                        applied_prop[apply[i]] = armor_prop[apply[i]];
                else
                        applied_prop[apply[i]] += armor_prop[apply[i]];
        }
        owner->set_temp("apply", applied_prop);
        set("equipped", "worn");
        owner->set("heart_modify",1);
        if(!owner->is_fighting()) {
                race=owner->query("race");
                if(file_size(RACE_D(race)+".c") > 0) RACE_D(race)->reset_attribute(owner);
        }
        return 1;
}

int wield()
{
        object owner, old_weapon;
        mapping weapon_prop;
        string *apply, type,race_weapon_prop,race;
        int flag;

        // Only character object can wear armors.
        owner = environment();
        if(!owner) 
        {
                log_file( "debug", "/feature/equip.c ERROR in wield():\n"+
                        this_object()->query("name") + "["+base_name(this_object())+"] �S�����ҵL�k�˳�. at:" + ctime(time()) + "\n" ); 
                return 0;
        }
        if( !owner->is_character() ) return 0;
        
        // Find owner's Race
        switch(owner->query("race"))
        {
                case "���~" :
                case "beast" :
                                race_weapon_prop="beast_weapon_prop";
                                break;
                case "���~" :
                case "monster" :
                                race_weapon_prop="monster_weapon_prop";
                                break;
                default : // default ����ϥ�
//                        return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�ä��A�X"+owner->query("race")+"�ϥΡC\n");
                        race_weapon_prop="weapon_prop";
                                                break;

        }
        
        // If already wielded, just recognize it.
        if( this_object()->query("equipped") ) return 1;

        // Check if we have "weapon_prop" defined.
        if( !mapp(weapon_prop = this_object()->query(race_weapon_prop)) )
                return notify_fail("�A�����D�o"+this_object()->query("unit")+this_object()->name()+"�n�p���@�Z���ϥΡC\n");

        //�l�a??
        if( this_object()->is_broken() ) 
                return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�l�a�F�C\n");
        if( this_object()->query_temp("no_energy") ) 
                return notify_fail("�o"+this_object()->query("unit")+this_object()->name()+"�w�g�S����q�F�C\n");       
        flag = this_object()->query("flag");

        if( flag & TWO_HANDED ) {
                if( owner->query_temp("weapon")
                ||      owner->query_temp("secondary_weapon")
                ||      owner->query_temp("armor/shield") )
                        return notify_fail("�Q�˳�"+this_object()->name()+"�����n���ťX����C\n");
                owner->set_temp("weapon", this_object());
        } else {

                // If we are are using any weapon?
                if( !(old_weapon = owner->query_temp("weapon")) )
                        owner->set_temp("weapon", this_object());

                else // If we still have a free hand? 
                if( !owner->query_temp("secondary_weapon")
                &&      !owner->query_temp("armor/shield") 
                &&      !(old_weapon->query("flag") & TWO_HANDED))
                {

                        // If we can wield this as secondary weapon?
                        if( ( flag & SECONDARY ) // �����O�P�˺����~��P�ɸ˳� 
                                && this_object()->query("skill_type") == old_weapon->query("skill_type") ) {
                                owner->set_temp("secondary_weapon", this_object());
                                set("co_equipped","wielded");
                                tell_object(owner,"["+this_object()->query("name")+"�w�]�w���ƪZ��]\n");
                        // If we can switch our old weapon to secondary weapon ?
                        } else if( ( (int)old_weapon->query("flag") & SECONDARY ) // �����O�P�˺����~��P�ɸ˳� 
                                && this_object()->query("skill_type") == old_weapon->query("skill_type") ) {
                                old_weapon->unequip();
                                owner->set_temp("weapon", this_object());
                                old_weapon->wield();

                        // We need unwield our old weapon before we can use this one.
                        } else
                                return notify_fail("�A��������U"+old_weapon->name()+"�~��˳�"+this_object()->name()+"�C\n");
//                              ����: �۰ʨ���������Z��
//                              �q/cmds/std/wield.c�������/feature/equip.c 
//                              -Alickyuen@DS 2005 Aug 3
//                      {
//                              string str, gender;
//
//                              if( old_weapon->unequip() )
//                              {
//                                      if( !stringp(str = old_weapon->query("unwield_msg")) )
//                                              str = "$N��U�⤤��$n�C\n";
//
//                                      if(owner->query_temp("hide")+owner->query_temp("invis")<1) message_vision(str, owner, old_weapon);
//                                      else
//                                      {       
//                                              if(owner->query("gender")=="�k��") gender="�p";
//                                              else gender="�A";
//                                              str=replace_string( str, "$N", gender);
//                                              str=replace_string( str, "$n", old_weapon->name());
//                                              tell_object(owner,str);
//                                      }
//                                      owner->set_temp("weapon", this_object());
//                              }
//                      }
                // We have both hands wearing something.
                } else
                        return notify_fail("�A�����ťX�@����~��ϥ�"+this_object()->name()+"�C\n");
        }

        apply = keys(weapon_prop);
        for(int i = 0; i<sizeof(apply); i++)
                owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);

        owner->reset_action();
        set("equipped", "wielded");
        
        owner->set("heart_modify",1);
        if(!owner->is_fighting())
        {
                race=owner->query("race");
                if(file_size(RACE_D(race)+".c") > 0) RACE_D(race)->reset_attribute(owner);
        }
        return 1;
}

int unequip()
{
        object owner,second_wp;
        mapping prop, applied_prop;
        string *apply, equipped,race_armor_prop,race_weapon_prop,race_armor_type,race;

        if( !(owner = environment())->is_character() ) return 0;

        if( !stringp(equipped = this_object()->query("equipped")) )
                return notify_fail("�A�ثe�èS���˳�"+this_object()->name()+"�C\n");
        
        // Find owner's Race
        switch(owner->query("race"))
        {
                case "���~" :
                case "beast" :
                                race_armor_prop="beast_armor_prop";
                                race_armor_type="beast_armor_type";
                                race_weapon_prop="beast_weapon_prop";
                                break;
                case "���~" :
                case "monster" :
                                race_armor_prop="monster_armor_prop";
                                race_armor_type="monster_armor_type";
                                race_weapon_prop="monster_weapon_prop";
                                break;
                default :
                                race_armor_prop="armor_prop";
                                race_armor_type="armor_type";
                                race_weapon_prop="weapon_prop";
                                break;

        }
        if( equipped=="wielded" )
        {
                if( (object)owner->query_temp("weapon") == this_object() )
                {
                        owner->delete_temp("weapon");
                        if( second_wp=(object)owner->query_temp("secondary_weapon"))
                        {
                                second_wp->unequip();
                                second_wp->wield();
                        }
                }
                else if( (object)owner->query_temp("secondary_weapon") == this_object() )
                        {
                                owner->delete_temp("secondary_weapon");
                        }
                prop = this_object()->query(race_weapon_prop);
                owner->reset_action();
        } else if( equipped=="worn" ) {
                owner->delete_temp("armor/" + this_object()->query(race_armor_type) );
                prop = this_object()->query(race_armor_prop);
        }

        apply = keys(prop);
        applied_prop = owner->query_temp("apply");
        if(sizeof(prop))
        {
                for(int i = 0; i<sizeof(apply); i++)
                {
                        // To support array apply, we cannot add_temp() here.
                        if(sizeof(apply)<=i) continue;
                        if(!undefinedp(prop[apply[i]])) applied_prop[apply[i]] -= prop[apply[i]];
                }
        }
        //owner->set_temp("apply",applied_prop);
        delete("equipped");
        if(stringp(this_object()->query("co_equipped"))) delete("co_equipped");
        
        owner->set("heart_modify",1);
        if(!owner->is_fighting())
        {
                race=owner->query("race");
                if(file_size(RACE_D(race)+".c") > 0) RACE_D(race)->reset_attribute(owner);
        }
        
        return 1;
}

