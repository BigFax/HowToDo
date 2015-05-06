/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.service;

import com.supinfo.supsms.dao.RoleDao;
import com.supinfo.supsms.entity.Role;
import javax.ejb.EJB;
import javax.ejb.Stateless;

/**
 *
 * @author clement
 */
@Stateless
public class RoleService {
    
    @EJB
    private RoleDao roleDao;
    
    public Role processRoleRegistration(Role newRole) {
        this.roleDao.registerNewRole(newRole);   
        return newRole;
    } 
    
    public Object processRoleModification(Role modifiedRole) {
        return this.roleDao.modifyRegisterRole(modifiedRole);
    } 
    
    public Role findRoleByName(String name) {
        return this.roleDao.findRoleByName(name);
    }

}
