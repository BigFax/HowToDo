<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">Administration panel</h1>

<div class="main_sep"></div>
<div class="col-lg">
    <table class="table table-striped table-bordered table-condensed ">
        <tr>
            <th>Id</th>
            <th>Firstname</th>
            <th>Lastname</th>
            <th>Email</th>
            <th>Phone Number</th>
            <th>Delete</th>
        </tr>
        <c:forEach items="${userList}" var="user">
            <tr>
                <td><c:out value="${user.getId()}" /></td>
                <td><c:out value="${user.getFirstName()}" /></td>
                <td><c:out value="${user.getLastName()}" /></td>
                <td><c:out value="${user.getEmail()}" /></td>
                <td><c:out value="${user.getPhoneNumber()}" /></td>
                <form method="POST">
                    <input type="hidden" name="id" value="${user.getId()}"/>
                    <td><input type="submit" value="Delete User" class="btn btn-danger"></td>
                </form>
            </tr>
        </c:forEach>
    </table>
</div>
<%@ include file="/footer.jsp"%>