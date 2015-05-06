/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao.jpa;

import com.supinfo.supsms.dao.RoleDao;
import com.supinfo.supsms.entity.Role;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 *
 * @author clement
 */
@Stateless
public class JpaRoleDao implements RoleDao{
    
    @PersistenceContext
    private EntityManager em;
    
    
    @Override
    public Role registerNewRole(Role newRole){
        try {
            this.em.persist(newRole);   
        } catch(Exception e) {
            System.out.print(e);
        }
        return newRole;
    }
    
    @Override
    public Object modifyRegisterRole(Role modifiedRole) {
        String result = "";
        Role dbRole = this.findRoleById(modifiedRole.getId());

        if(dbRole.getId() != null && dbRole.getId().equals(modifiedRole.getId())) {
            try {
                this.em.persist(modifiedRole);
            } catch(Exception e) {
                result = "Error while save your modification.";
            }
        } else {
            result = "Error while save your modification.";
        }
        return result.equals("") ? modifiedRole : result;
    }
    
    @Override
    public Role findRoleById(Long userId) {
        Role resultRole;
        try {
            resultRole = em.find(Role.class, userId);
        } catch(Exception e) {
            resultRole = new Role();
        }
        
        return resultRole;
    }
    
    @Override
    public Role findRoleByName(String roleName){
        Query query = this.em.createQuery("SELECT role FROM Role AS role WHERE role.roleName = :role"); 
        query.setParameter("role", roleName);
        Role resultRole;
        try {
            resultRole = (Role)query.getSingleResult();    
        } catch(Exception e) {
            resultRole = new Role();
        }
        return resultRole;
    }
}
