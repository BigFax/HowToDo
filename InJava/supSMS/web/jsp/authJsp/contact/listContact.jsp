<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">List Contacts</h1>

<div class="main_sep"></div>

<div class="sentence">
    <strong>Manage</strong> all your contacts on this page.<br>
</div>
        
<div class="col-lg">
    <table class="table table-striped table-bordered table-condensed ">
        
        <c:if test="${!empty contactList.get(0)}">
        <tr>
            <th>Id</th>
            <th>Firstname</th>
            <th>Lastname</th>
            <th>Email</th>
            <th>Address Postal</th>
            <th>Phone Number</th>
            <th>Update</th>
            <th>Delete</th>
        </tr>
        <c:forEach items="${contactList}" var="contact">
            <tr>
                <td><c:out value="${contact.getId()}" /></td>
                <td><c:out value="${contact.getFirstName()}" /></td>
                <td><c:out value="${contact.getLastName()}" /></td>
                <td><c:out value="${contact.getEmail()}" /></td>
                <td><c:out value="${contact.getPostalAddress()}" /></td>
                <td><c:out value="${contact.getPhoneNumber()}" /></td>
                <c:url value="/auth/updateContact" var="updateContactUrl" />
                <form method="GET" action="${updateContactUrl}">
                    <input type="hidden" name="id" value="${contact.getId()}"/>
                    <td><input type="submit" value="Update Contact" class="btn btn-primary"></td>
                </form>
                <c:url value="/auth/deleteContact" var="deleteContactUrl" />
                <form method="POST" action="${deleteContactUrl}">
                    <input type="hidden" name="id" value="${contact.getId()}"/>
                    <td><input type="submit" value="Delete Contact" class="btn btn-danger"></td>
                </form>
            </tr>
        </c:forEach>
        </c:if>
    </table>
    <c:url value="/auth/createContact" var="createContactUrl" />
    <a href="${createContactUrl}" class="btn btn-primary-custom" role="button">CREATE A NEW CONTACT</a>
</div>

<%@ include file="/footer.jsp"%>