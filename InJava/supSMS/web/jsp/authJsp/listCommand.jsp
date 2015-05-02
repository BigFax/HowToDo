<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<h1 id="page_title">List Commands</h1>

<div class="main_sep"></div>

<div class="sentence">
    <strong>Manage</strong> all your commands on this page.<br>
</div>
        
<div class="col-lg">
    <table class="table table-striped table-bordered table-condensed ">
        
        <c:if test="${!empty commandList.get(0)}">
        <tr>
            <th>Id</th>
            <th>Begin At</th>
            <th>Expire At</th>
            <th>Price</th>
        </tr>
        <c:forEach items="${commandList}" var="command">
            <tr>
                <td><c:out value="${command.getId()}" /></td>
                <td><c:out value="${command.getBegin_at()}" /></td>
                <td><c:out value="${command.getExpire_at()}" /></td>
                <td><c:out value="${command.getPrice()}" /></td>
            </tr>
        </c:forEach>
        </c:if>
    </table>
</div>

<%@ include file="/footer.jsp"%>