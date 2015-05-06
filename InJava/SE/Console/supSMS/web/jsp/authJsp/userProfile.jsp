<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<c:url value="/register" var="registerUrl" />
<h1 id="page_title">Update Profil Page</h1>

<div class="main_sep"></div>

<div class="sentence">
    <strong>Update</strong> your profil data easily with the form below.<br>
</div>

<form method="POST">
    <input type="hidden" name="id" value="${user.getId()}"/>
    <div class="form-part">
        <input type="text" name="firstname" class="form-input" placeholder="Your first name..." value="${user.getFirstName()}" />
        <input type="text" name="lastname" class="form-input" placeholder="Your last name..." value="${user.getLastName()}" />
        <input type="email" name="email" class="form-input" placeholder="Your email..." value="${user.getEmail()}" />
    </div>
    <div class="form-part">
        <input type="number" name="phonenumber" class="form-input" placeholder="Your phone number..." value="${user.getPhoneNumber()}" />
        <input type="number" name="creditcard" class="form-input" placeholder="Your credit card..." value="${user.getCreditCard()}" />
        <input type="password" name="password" class="form-input" placeholder="Your password..." value="${user.getPassword()}" />
    </div>
    
    <div style="text-align: center;">
        <input type="submit" class="btn btn-primary-custom" value="Update my profil" />
    </div>
</form>
    
<%@ include file="/footer.jsp"%>