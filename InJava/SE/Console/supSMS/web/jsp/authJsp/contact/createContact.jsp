<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">Create Contact</h1>

<div class="main_sep"></div>

<div class="sentence">
    <strong>Create</strong> your contact with the form below.<br>
</div>

<form method="POST">
    <div class="form-part">
        <input type="text" name="firstname" class="form-input" placeholder="Your contact first name..." />
        <input type="text" name="lastname" class="form-input" placeholder="Your contact last name..." />
        <input type="email" name="email" class="form-input" placeholder="Your contact email..." />
    </div>
    <div class="form-part">
        <input type="text" name="postaladdress" class="form-input" placeholder="Your contact postal address..." />
        <input type="number" name="phonenumber" class="form-input" placeholder="Your contact phone number..." />
    </div>
    
    <div style="clear: both;"></div>
    
    <div style="text-align: center;">
        <input type="submit" class="btn btn-primary-custom" value="Create a new contact" />
    </div>
</form>

<%@ include file="/footer.jsp"%>