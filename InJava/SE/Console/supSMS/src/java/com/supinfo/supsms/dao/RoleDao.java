/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao;

import com.supinfo.supsms.entity.Role;
import javax.ejb.Local;

/**
 *
 * @author clement
 */
@Local
public interface RoleDao {
    
    public Role registerNewRole(Role newRole);
    
    public Object modifyRegisterRole(Role modifiedRole);
    
    public Role findRoleById(Long userId);
    
    public Role findRoleByName(String roleName);
}
