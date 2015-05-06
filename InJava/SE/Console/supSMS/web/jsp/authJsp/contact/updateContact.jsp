<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">Update Contact</h1>

<div class="sentence">
    <strong>Update</strong> any contact you want. Just complete the form below.<br>
    The <strong>phone number</strong> need to be a real phone number.<br>
</div>

<div class="main_sep"></div>
<form method="POST">
    <input type="hidden" name="id" value="${contact.getId()}"/>
    <div class="form-part">
        <input type="text" name="firstname" class="form-input" placeholder="Your contact first name..." value="${contact.getFirstName()}" />
        <input type="text" name="lastname" class="form-input" placeholder="Your contact last name..." value="${contact.getLastName()}" />
        <input type="email" name="email" class="form-input" placeholder="Your contact email..." value="${contact.getEmail()}" />
    </div>
    <div class="form-part">
        <input type="text" name="postaladdress" class="form-input" placeholder="Your contact postal address..." value="${contact.getPostalAddress()}" />
        <input type="number" name="phonenumber" class="form-input" placeholder="Your contact phone number..."  value="${contact.getPhoneNumber()}" />
    </div>
    
    <div style="clear: both;"></div>
    
    <div style="text-align: center;">
        <input type="submit" class="btn btn-primary-custom" value="Update your contact" />
    </div>
</form>

<%@ include file="/footer.jsp"%>