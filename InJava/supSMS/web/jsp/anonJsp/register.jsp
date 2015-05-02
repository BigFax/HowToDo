<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">Register page</h1>

<div class="main_sep"></div>

<div class="sentence">
    <strong>Registration</strong> is really easy and fast, less than one minute.<br>
    You just need to give us informations below and enjoy the service ;)
</div>
<form method="POST">
    <div class="form-part">
        <input type="text" name="firstname" class="form-input" placeholder="Your first name..." />
        <input type="text" name="lastname" class="form-input" placeholder="Your last name..." />
        <input type="email" name="email" class="form-input" placeholder="Your email..." />
    </div>
    <div class="form-part">
        <input type="number" name="phonenumber" class="form-input" placeholder="Your phone number..." />
        <input type="number" name="creditcard" class="form-input" placeholder="Your credit card..." />
        <input type="password" name="password" class="form-input" placeholder="Your password..." />
    </div>
    
    <div style="text-align: center;">
        <input type="submit" class="btn btn-primary-custom" value="I register !" />
    </div>
</form>



<%@ include file="/footer.jsp"%>
